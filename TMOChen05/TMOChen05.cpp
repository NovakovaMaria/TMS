/* --------------------------------------------------------------------------- *
 * TMOChen05.cpp: implementation of the TMOChen05 class.   *
 * --------------------------------------------------------------------------- */

#include "TMOChen05.h"

/* --------------------------------------------------------------------------- *
 * Constructor serves for describing a technique and input parameters          *
 * --------------------------------------------------------------------------- */
TMOChen05::TMOChen05()
{
	SetName(L"Chen05");					  // TODO - Insert operator name
	SetDescription(L"Tone reproduction: a perspective from luminance-driven perceptual grouping"); // TODO - Insert description

	Theta.SetName(L"Theta");				// TODO - Insert parameters names
	Theta.SetDescription(L"ParameterDescription"); // TODO - Insert parameter descriptions
	Theta.SetDefault(1.5);							// TODO - Add default values
	Theta = 1.5;
	Theta.SetRange(1.5, 2.0); // TODO - Add acceptable range if needed
	this->Register(Theta);

   Delta.SetName(L"Delta");				// TODO - Insert parameters names
	Delta.SetDescription(L"ParameterDescription"); // TODO - Insert parameter descriptions
	Delta.SetDefault(0.5);							// TODO - Add default values
	Delta = 0.5;
	Delta.SetRange(0.5, 1.0); // TODO - Add acceptable range if needed
	this->Register(Delta);
}

#define rgb2luminance(R,G,B) (R*0.2126 + G*0.7152 + B*0.0722)
unsigned int IMAGE_HEIGHT;
unsigned int IMAGE_WIDTH;

typedef vector< vector<float> > PixelMatrix;

typedef vector< vector<double> > PixelDoubleMatrix;

typedef std::vector< vector<int> > PixelIntMatrix;

typedef vector< vector<long> > PixelLongMatrix;

struct Point{
   unsigned short x,y;
};
struct Signature{
   double s;
   double w;
};
typedef std::vector<Point> PointVector;
typedef std::vector<float> HistogramVector;
typedef std::vector<Signature> SignatureVector;
typedef std::vector<int> UnvisitedVector;
typedef std::vector<int> NeighbourContainer;
struct Block_Record{
   PointVector Memebers;
   NeighbourContainer Neighbours;
   float Sum;
   unsigned int Count;
   HistogramVector logHistogram;
   SignatureVector blockSignature;
   
   
};
struct Region_Record{
   PointVector Members;
   float Sum;
   unsigned int Count;
   HistogramVector logHistogram;
   SignatureVector regionSignature;
};

typedef std::vector<Block_Record > Blocks;
typedef std::vector<Region_Record > Regions;

float emdFunctionBB(int firstBlock, int secondBlock, Blocks& pixelBlocks)
{
   cv::Mat sign1(cv::Size(2,3),CV_32FC1);
   cv::Mat sign2(cv::Size(2,3),CV_32FC1);
   for(int i=0;i < 3; i++)
   {
      sign1.at<float>(i,0) = pixelBlocks[firstBlock].blockSignature[i].s;
      sign1.at<float>(i,1) = pixelBlocks[firstBlock].blockSignature[i].w;
   }
   for(int k=0; k < 3; k++)
   {
      sign2.at<float>(k,0) = pixelBlocks[secondBlock].blockSignature[k].s;
      sign2.at<float>(k,1) = pixelBlocks[secondBlock].blockSignature[k].w;
   } 
   return cv::EMD(sign1,sign2,cv::DIST_L2);
   
}

float emdFunctionBR(int block, int region, Blocks& pixelBlocks, Regions& pixelRegions)
{
   cv::Mat sign1(cv::Size(2,3),CV_32FC1);
   cv::Mat sign2(cv::Size(2,3),CV_32FC1);
   for(int i=0;i < 3; i++)
   {
      sign1.at<float>(i,0) = pixelBlocks[block].blockSignature[i].s;
      sign1.at<float>(i,1) = pixelBlocks[block].blockSignature[i].w;
   }
   for(int k=0; k < 3; k++)
   {
      sign2.at<float>(k,0) = pixelRegions[region].regionSignature[k].s;
      sign2.at<float>(k,1) = pixelRegions[region].regionSignature[k].w;
   } 
   return cv::EMD(sign1,sign2,cv::DIST_L2);
   
}

bool isValid(int x, int y, int category, PixelIntMatrix& pixels, PixelIntMatrix& pixelCategories)
{
   if(x<0 || x>= IMAGE_HEIGHT || y<0 || y>= IMAGE_WIDTH || pixelCategories[x][y] != category || pixels[x][y] == 1)
   {
      return false;
   }
   return true;
}


void GroupNeighbours(int x, int y, int group, PixelIntMatrix& pixels, PixelIntMatrix& pixelCategories, Blocks& pixelBlocks)
{
   vector<pair<int, int>> queue;
   pair<int, int> p(x,y);
   queue.push_back(p);

   pixels[x][y] = 1;


   while(queue.size() > 0)
   {
      pair<int,int> currPixel = queue[queue.size() - 1];
      queue.pop_back();

      int posX = currPixel.first;
      int posY = currPixel.second;
      if(isValid(posX+1, posY, group, pixels, pixelCategories))
      {
         pixels[posX+1][posY] = 1;
         p.first = posX+1;
         p.second = posY;
         queue.push_back(p);
      }
      if(!(isValid(posX+1, posY, group, pixels, pixelCategories)))
      {
         if(posX+1>=0 && posX+1< IMAGE_HEIGHT && posY>=0 && posY<IMAGE_WIDTH && pixels[posX+1][posY]!=1) 
         {
            if(!(std::find(pixelBlocks[pixelCategories[posX+1][posY]].Neighbours.begin(), pixelBlocks[pixelCategories[posX+1][posY]].Neighbours.end(), pixelCategories[posX][posY]) != pixelBlocks[pixelCategories[posX+1][posY]].Neighbours.end())){
               pixelBlocks[pixelCategories[posX+1][posY]].Neighbours.push_back(pixelCategories[posX][posY]);
            }
            if(!(std::find(pixelBlocks[pixelCategories[posX][posY]].Neighbours.begin(), pixelBlocks[pixelCategories[posX][posY]].Neighbours.end(), pixelCategories[posX+1][posY]) != pixelBlocks[pixelCategories[posX][posY]].Neighbours.end())){
               pixelBlocks[pixelCategories[posX][posY]].Neighbours.push_back(pixelCategories[posX+1][posY]);
            }
         }
      }

      if(isValid(posX-1, posY, group, pixels, pixelCategories))
      {
         pixels[posX-1][posY] = 1;
         p.first = posX-1;
         p.second = posY;
         queue.push_back(p);
      }
      if(!(isValid(posX-1, posY, group, pixels, pixelCategories)))
      {
         if(posX-1>=0 && posX-1< IMAGE_HEIGHT && posY>=0 && posY<IMAGE_WIDTH && pixels[posX-1][posY]!=1)
         {
            if(!(std::find(pixelBlocks[pixelCategories[posX-1][posY]].Neighbours.begin(), pixelBlocks[pixelCategories[posX-1][posY]].Neighbours.end(), pixelCategories[posX][posY]) != pixelBlocks[pixelCategories[posX-1][posY]].Neighbours.end())){
               pixelBlocks[pixelCategories[posX-1][posY]].Neighbours.push_back(pixelCategories[posX][posY]);
            }
            if(!(std::find(pixelBlocks[pixelCategories[posX][posY]].Neighbours.begin(), pixelBlocks[pixelCategories[posX][posY]].Neighbours.end(), pixelCategories[posX-1][posY]) != pixelBlocks[pixelCategories[posX][posY]].Neighbours.end())){
               pixelBlocks[pixelCategories[posX][posY]].Neighbours.push_back(pixelCategories[posX-1][posY]);
            }
         }
         
      }
      if(isValid(posX, posY+1, group, pixels, pixelCategories))
      {
         pixels[posX][posY+1] = 1;
         p.first = posX;
         p.second = posY+1;
         queue.push_back(p);
      }
      if(!(isValid(posX, posY+1, group, pixels, pixelCategories)))
      {
         if(posX>=0 && posX< IMAGE_HEIGHT && posY+1>=0 && posY+1<IMAGE_WIDTH && pixels[posX][posY+1]!=1)
         {
            if(!(std::find(pixelBlocks[pixelCategories[posX][posY+1]].Neighbours.begin(), pixelBlocks[pixelCategories[posX][posY+1]].Neighbours.end(), pixelCategories[posX][posY]) != pixelBlocks[pixelCategories[posX][posY+1]].Neighbours.end())){
               pixelBlocks[pixelCategories[posX][posY+1]].Neighbours.push_back(pixelCategories[posX][posY]);
            }
            if(!(std::find(pixelBlocks[pixelCategories[posX][posY]].Neighbours.begin(), pixelBlocks[pixelCategories[posX][posY]].Neighbours.end(), pixelCategories[posX][posY+1]) != pixelBlocks[pixelCategories[posX][posY]].Neighbours.end())){
               pixelBlocks[pixelCategories[posX][posY]].Neighbours.push_back(pixelCategories[posX][posY+1]);
            }
         }
         
      }
      if(isValid(posX, posY-1, group, pixels, pixelCategories))
      {
         pixels[posX][posY-1] = 1;
         p.first = posX;
         p.second = posY-1;
         queue.push_back(p);
      }
      if(!(isValid(posX, posY-1, group, pixels, pixelCategories)))
      {
         if(posX>=0 && posX< IMAGE_HEIGHT && posY-1>=0 && posY-1<IMAGE_WIDTH && pixels[posX][posY-1]!=1)
         {
            if(!(std::find(pixelBlocks[pixelCategories[posX][posY-1]].Neighbours.begin(), pixelBlocks[pixelCategories[posX][posY-1]].Neighbours.end(), pixelCategories[posX][posY]) != pixelBlocks[pixelCategories[posX][posY-1]].Neighbours.end())){
               pixelBlocks[pixelCategories[posX][posY-1]].Neighbours.push_back(pixelCategories[posX][posY]);
            }
            if(!(std::find(pixelBlocks[pixelCategories[posX][posY]].Neighbours.begin(), pixelBlocks[pixelCategories[posX][posY]].Neighbours.end(), pixelCategories[posX][posY-1]) != pixelBlocks[pixelCategories[posX][posY]].Neighbours.end())){
               pixelBlocks[pixelCategories[posX][posY]].Neighbours.push_back(pixelCategories[posX][posY-1]);
            }
         }
         
      }

   }
}

void updateRegionSignature(int regionID, Regions& region, PixelDoubleMatrix& LogLuminancePixels)
{
   double maxlum = LogLuminancePixels[region[regionID].Members[0].y][region[regionID].Members[0].x];
   double minlum = LogLuminancePixels[region[regionID].Members[0].y][region[regionID].Members[0].x];
   region[regionID].logHistogram.clear();
   region[regionID].regionSignature.clear();
   for(int j=0; j < region[regionID].Members.size();j++)
   {
      int x = region[regionID].Members[j].x;
      int y = region[regionID].Members[j].y;
      double tmp = LogLuminancePixels[y][x];
      if(tmp > maxlum)
      {
         maxlum = tmp;
      }
      if(tmp < minlum)
      {
         minlum = tmp;
      }
      region[regionID].logHistogram.push_back(tmp);
   }
   double step = (maxlum-minlum)/3.0;
   double first_threshold = minlum + step;
   double second_threshold = first_threshold + step;
   double firstSectionLum =0.0, secondSectionLum=0.0, thirdSectionLum=0.0;
   double firstSectionCount=0.0, secondSectionCount=0.0, thirdSectionCount=0.0;
   for(int k = 0; k < region[regionID].logHistogram.size(); k++)
   {
      if(region[regionID].logHistogram[k] <= first_threshold)
      {
         firstSectionLum += region[regionID].logHistogram[k];
         firstSectionCount += 1.0;
      }
      else if(region[regionID].logHistogram[k] > first_threshold && region[regionID].logHistogram[k] <= second_threshold)
      {
         secondSectionLum += region[regionID].logHistogram[k];
         secondSectionCount += 1.0;
      }
      else{
         thirdSectionLum += region[regionID].logHistogram[k];
         thirdSectionCount += 1.0;
      }
   }
   double sumOfPixels = firstSectionCount + secondSectionCount + thirdSectionCount;
   double s1 = thirdSectionLum/thirdSectionCount;
   double w1 = thirdSectionCount/sumOfPixels;
   Signature signatureOfRegion;
   signatureOfRegion.s = s1;
   signatureOfRegion.w = w1;
   region[regionID].regionSignature.push_back(signatureOfRegion);
   double s2 = secondSectionLum/secondSectionCount;
   double w2 = secondSectionCount/sumOfPixels;
   signatureOfRegion.s = s2;
   signatureOfRegion.w = w2;
   region[regionID].regionSignature.push_back(signatureOfRegion);
   double s3 = firstSectionLum/firstSectionCount;
   double w3 = firstSectionCount/sumOfPixels;
   signatureOfRegion.s = s3;
   signatureOfRegion.w = w3;
   region[regionID].regionSignature.push_back(signatureOfRegion);
   //fprintf(stderr,"s1 %f sign1 %f\n",s1,region[regionID].regionSignature[0].s);
}



TMOChen05::~TMOChen05()
{
}

/* --------------------------------------------------------------------------- *
 * This overloaded function is an implementation of your tone mapping operator *
 * --------------------------------------------------------------------------- */
int TMOChen05::Transform()
{
	// Source image is stored in local parameter pSrc
	// Destination image is in pDst

	// Initialy images are in RGB format, but you can
	// convert it into other format
	//pSrc->Convert(TMO_Yxy); // This is format of Y as luminance
	//pDst->Convert(TMO_Yxy); // x, y as color information
   pSrc->Convert(TMO_RGB);
	double *pSourceData = pSrc->GetData();		// You can work at low level data
	double *pDestinationData = pDst->GetData(); // Data are stored in form of array
												// of three doubles representing
												// three colour components

   double *imageData = pSrc->GetData();
   int imageHeight = pSrc->GetHeight();
   int imageWidth = pSrc->GetWidth();
   IMAGE_HEIGHT = imageHeight;
   IMAGE_WIDTH = imageWidth;

   //cv::Mat image = cv::imread("/home/matthewlele/images/hdr_images/84y7.tif");
   double stonits = pSrc->GetStonits();
   PixelDoubleMatrix LogLuminancePixels(imageHeight, vector<double>(imageWidth, 0.0));
   double pixelR, pixelG, pixelB;
   cv::Mat image;
   cv::Mat finalImage;
   image = cv::Mat::zeros(imageHeight, imageWidth, CV_32F);
   //Getting log luminance of each pixel
   for(int j=0; j < imageHeight; j++)
   {
      for(int i=0; i<imageWidth; i++)
      {
         pixelR = *imageData++;
         pixelG = *imageData++;
         pixelB = *imageData++;
         LogLuminancePixels[j][i] = log(rgb2luminance(pixelR, pixelG, pixelB)+stonits);
         image.at<float>(j, i) = log(rgb2luminance(pixelR, pixelG, pixelB)+stonits);
         //image.at<cv::Vec3f>(j, i)[1] = pixelG;
         //image.at<cv::Vec3f>(j, i)[2] = pixelR;
      }
   }
   cv::normalize(image,image,0.0,1.0,cv::NORM_MINMAX, CV_32F);
   double imgMin, imgMax;
   cv::minMaxLoc(image, &imgMin, &imgMax);
   image.convertTo(finalImage, CV_8U, 255*(imgMax - imgMin));
   //cv::cvtColor(finalImage, finalImage, cv::COLOR_BGR2GRAY);
   cv::Mat contours;
   cv::Mat gray_img;
   cv::Mat testImage = cv::imread("/home/matthewlele/images/cadik/cadik-desk01.hdr");

   //cvtColor(image, gray_img, CV_RGB2GRAY);
   cv::Canny(finalImage, contours, 80, 240);
   cv::namedWindow("Canny");
   cv::imshow("Canny",contours);
   cv::waitKey(0);
   
   
   fprintf(stderr,"Image height: %d Image width: %d\n",imageHeight, imageWidth);
   Blocks pixelBlocks;
   int edgeDetected = 0;
   //creating Blocks of pixels from image
   for(int j=0; j < imageHeight-7; j+=8)
   {
      for(int i=0; i < imageWidth-7; i+=8)
      {
         Block_Record block;
         Point p;
         block.Sum = 0.0;
         block.Count = 0;
         edgeDetected = 0;
         for(int k =j; k < j+8; k++)
         {
            for(int l=i; l < i+8; l++)
            {
               if(contours.at<double>(k, l) != 0.0)
               {
                  edgeDetected = 1;
               }
               p.x = l;
               p.y = k;
               block.Count += 1;
               block.Sum += LogLuminancePixels[k][l];
               block.Memebers.push_back(p);
            }
         }
         if(edgeDetected == 1)
         {
            int x_value = i;
            int y_value = j;
            for(int first_row = 0; first_row < 4; first_row++)
            {
               Block_Record small_block;
               Point point;
               small_block.Count = 0;
               small_block.Sum = 0.0;
               for(int k =y_value; k < y_value+2; k++)
               {
                  for(int l=x_value; l < x_value+2; l++)
                  {
                     point.x = l;
                     point.y = k;
                     small_block.Count += 1;
                     small_block.Sum += LogLuminancePixels[k][l];
                     small_block.Memebers.push_back(point);
                  }
               }
               pixelBlocks.push_back(small_block);
               x_value+=2;
            }
            x_value = i;
            y_value += 2;
            for(int second_row = 0; second_row < 4; second_row++)
            {
               Block_Record small_block;
               Point point;
               small_block.Count = 0;
               small_block.Sum = 0.0;
               for(int k =y_value; k < y_value+2; k++)
               {
                  for(int l=x_value; l < x_value+2; l++)
                  {
                     point.x = l;
                     point.y = k;
                     small_block.Count += 1;
                     small_block.Sum += LogLuminancePixels[k][l];
                     small_block.Memebers.push_back(point);
                  }
               }
               pixelBlocks.push_back(small_block);
               x_value+=2;
            }
            x_value = i;
            y_value += 2;
            for(int third_row = 0; third_row < 4; third_row++)
            {
               Block_Record small_block;
               Point point;
               small_block.Count = 0;
               small_block.Sum = 0.0;
               for(int k =y_value; k < y_value+2; k++)
               {
                  for(int l=x_value; l < x_value+2; l++)
                  {
                     point.x = l;
                     point.y = k;
                     small_block.Count += 1;
                     small_block.Sum += LogLuminancePixels[k][l];
                     small_block.Memebers.push_back(point);
                  }
               }
               pixelBlocks.push_back(small_block);
               x_value+=2;
            }
            x_value = i;
            y_value += 2;
            for(int fourth_row = 0; fourth_row < 4; fourth_row++)
            {
               Block_Record small_block;
               Point point;
               small_block.Count = 0;
               small_block.Sum = 0.0;
               for(int k =y_value; k < y_value+2; k++)
               {
                  for(int l=x_value; l < x_value+2; l++)
                  {
                     point.x = l;
                     point.y = k;
                     small_block.Count += 1;
                     small_block.Sum += LogLuminancePixels[k][l];
                     small_block.Memebers.push_back(point);
                  }
               }
               pixelBlocks.push_back(small_block);
               x_value+=2;
            }
         }
         else{
            pixelBlocks.push_back(block);
         }
         
      }
   }
   fprintf(stderr,"Amount of blocks %d\n",pixelBlocks.size());

   //Calculating signature for each pixel
   for(int i=0; i < pixelBlocks.size();i++)
   {
      double maxlum = LogLuminancePixels[pixelBlocks[i].Memebers[0].y][pixelBlocks[i].Memebers[0].x];
      double minlum = LogLuminancePixels[pixelBlocks[i].Memebers[0].y][pixelBlocks[i].Memebers[0].x];
      for(int j=0; j < pixelBlocks[i].Memebers.size();j++)
      {
         int x = pixelBlocks[i].Memebers[j].x;
         int y = pixelBlocks[i].Memebers[j].y;
         double tmp = LogLuminancePixels[y][x];
         if(tmp > maxlum)
         {
            maxlum = tmp;
         }
         if(tmp < minlum)
         {
            minlum = tmp;
         }
         pixelBlocks[i].logHistogram.push_back(tmp);
      }
      double step = (maxlum-minlum)/3.0;
      double first_threshold = minlum + step;
      double second_threshold = first_threshold + step;
      double firstSectionLum =0.0, secondSectionLum=0.0, thirdSectionLum=0.0;
      double firstSectionCount=0.0, secondSectionCount=0.0, thirdSectionCount=0.0;
      for(int k = 0; k < pixelBlocks[i].logHistogram.size(); k++)
      {
         if(pixelBlocks[i].logHistogram[k] <= first_threshold)
         {
            firstSectionLum += pixelBlocks[i].logHistogram[k];
            firstSectionCount += 1.0;
         }
         else if(pixelBlocks[i].logHistogram[k] > first_threshold && pixelBlocks[i].logHistogram[k] <= second_threshold)
         {
            secondSectionLum += pixelBlocks[i].logHistogram[k];
            secondSectionCount += 1.0;
         }
         else{
            thirdSectionLum += pixelBlocks[i].logHistogram[k];
            thirdSectionCount += 1.0;
         }
      }
      double sumOfPixels = firstSectionCount + secondSectionCount + thirdSectionCount;
      double s1 = thirdSectionLum/thirdSectionCount;
      double w1 = thirdSectionCount/sumOfPixels;
      Signature signatureOfBlock;
      signatureOfBlock.s = s1;
      signatureOfBlock.w = w1;
      pixelBlocks[i].blockSignature.push_back(signatureOfBlock);
      double s2 = secondSectionLum/secondSectionCount;
      double w2 = secondSectionCount/sumOfPixels;
      signatureOfBlock.s = s2;
      signatureOfBlock.w = w2;
      pixelBlocks[i].blockSignature.push_back(signatureOfBlock);
      double s3 = firstSectionLum/firstSectionCount;
      double w3 = firstSectionCount/sumOfPixels;
      signatureOfBlock.s = s3;
      signatureOfBlock.w = w3;
      pixelBlocks[i].blockSignature.push_back(signatureOfBlock);
 
   }
   
   PixelIntMatrix pixelsGrp(imageHeight, vector<int>(imageWidth,0));
   PixelIntMatrix visitedPixels(imageHeight, vector<int>(imageWidth,0));
   //calculating each pixel's group
   for(int i=0; i < pixelBlocks.size();i++)
   {
      for(int k=0; k < pixelBlocks[i].Memebers.size();k++)
      {
         int x = pixelBlocks[i].Memebers[k].x;
         int y = pixelBlocks[i].Memebers[k].y;
         pixelsGrp[y][x] = i;
      }
   }
   fprintf(stderr,"height: %d width: %d\n",imageHeight,imageWidth);
   //finding neighbouring blocks of each block
   for(int i=0; i < pixelBlocks.size();i++)
   {
      int x = pixelBlocks[i].Memebers[0].x;
      int y = pixelBlocks[i].Memebers[0].y;
      GroupNeighbours(y,x, pixelsGrp[y][x], visitedPixels, pixelsGrp, pixelBlocks);
   }
   
   
   UnvisitedVector UnvistitedBlocks(pixelBlocks.size(),0);
   Regions blocksRegions;
   
   double theta = 0.3; 
   double delta = 0.5;
   int unvisited = pixelBlocks.size();
   int regionID = 0;
   int counterTMP = 0;
   int chosedBlockID = 0;
   vector<int> queue;
   fprintf(stderr,"%g %g\n",theta, delta);
   
   while(unvisited > 0)
   {
      queue.clear();
      float biggestS1 = 0.0;
      int brightestBlockID = 0;
      for(int i=0; i < pixelBlocks.size();i++)
      {
         if(UnvistitedBlocks[i]==0 && pixelBlocks[i].blockSignature[0].s > biggestS1)
         {
            biggestS1 = pixelBlocks[i].blockSignature[0].s;
            brightestBlockID = i;
         }
      }
      Region_Record region;
      region.regionSignature.push_back(pixelBlocks[brightestBlockID].blockSignature[0]);
      region.regionSignature.push_back(pixelBlocks[brightestBlockID].blockSignature[1]);
      region.regionSignature.push_back(pixelBlocks[brightestBlockID].blockSignature[2]);
      blocksRegions.push_back(region);
      queue.push_back(brightestBlockID);
      
      while(queue.size() > 0)
      {
         float smallest  = 5.0;
         int tmpID=0;
         for(int l=0;l < queue.size();l++)
         {
            float tmp = emdFunctionBR(queue[l],regionID,pixelBlocks,blocksRegions);
            if(tmp < smallest )
            {
               smallest = tmp;
               tmpID = l;
            }
         }
         //fprintf(stderr,"Smallest EMD %g\n",smallest);
         //fprintf(stderr,"Regions %d size %d id: %d\n",blocksRegions.size(), blocksRegions[regionID].Members.size(),regionID);
         chosedBlockID = queue[tmpID];
         if(smallest < theta)
         {
            queue.erase(queue.begin() + tmpID);
            for(int mem=0;mem < pixelBlocks[chosedBlockID].Memebers.size();mem++)
            {
               blocksRegions[regionID].Members.push_back(pixelBlocks[chosedBlockID].Memebers[mem]);
            }
            counterTMP += 1;
            fprintf(stderr,"Chosed block %d region %d iterations %d distance %f queue %d\n",chosedBlockID,blocksRegions[regionID].Members.size(),counterTMP, smallest, queue.size());
            //blocksRegions[regionID].Members = pixelBlocks[chosedBlockID].Memebers;
            UnvistitedBlocks[chosedBlockID] = 1;
            unvisited -= 1;
            //TODO
            
            for(int n=0; n< pixelBlocks[chosedBlockID].Neighbours.size();n++)
            {
               if(UnvistitedBlocks[pixelBlocks[chosedBlockID].Neighbours[n]] == 0)
               {
                  
                  float tmpEMD = emdFunctionBB(chosedBlockID,pixelBlocks[chosedBlockID].Neighbours[n], pixelBlocks);
                  if(tmpEMD < delta)
                  {
                     if(!(std::find(queue.begin(),queue.end(),pixelBlocks[chosedBlockID].Neighbours[n])!= queue.end()))
                     {
                        //fprintf(stderr,"Neighbour of block %d num %d\n",chosedBlockID,n);
                        queue.push_back(pixelBlocks[chosedBlockID].Neighbours[n]);
                     }
                     
                  }
               }
            }
            updateRegionSignature(regionID, blocksRegions, LogLuminancePixels);
            //fprintf(stderr,"Region %d s1 %f\n",regionID,blocksRegions[regionID].regionSignature[0].s);
            
         }
         else{
            
            break;
         }
      }
      regionID += 1;
   }
   PixelIntMatrix visitedRegionPixels(imageHeight, vector<int>(imageWidth,0)); 
   int pixelRegionCount =0;
   for(int m=0; m < blocksRegions.size();m++)
   {
      fprintf(stderr,"Region %d members %d \n",m,blocksRegions[m].Members.size());
      pixelRegionCount+= blocksRegions[m].Members.size();
      for(int i =0; i < blocksRegions[m].Members.size();i++)
      {
         int x = blocksRegions[m].Members[i].x;
         int y = blocksRegions[m].Members[i].y;
         visitedRegionPixels[y][x] = 1;
      }
      
      
   }
   fprintf(stderr,"Pixels %d,region size %d\n",pixelRegionCount,blocksRegions.size());
   int pixelBlockCount =0;
   for(int p=0; p<pixelBlocks.size();p++)
   {
      pixelBlockCount += pixelBlocks[p].Memebers.size();
   }
   fprintf(stderr,"Block pixels %d\n",pixelBlockCount);
   int unvisitedRegionCount = 0;
   for(int k=0; k < imageHeight; k++)
   {
      for(int p=0; p < imageWidth; p++)
      {
         if(visitedRegionPixels[k][p] == 0)
         {
            unvisitedRegionCount++;
         }
      }
   }
   fprintf(stderr,"unvisited %d\n",unvisitedRegionCount);
   

   //V(x,y) = 1/Z(x,y).(sum[each pixel in region i,j](LogL(i,j).Gxy(i,j).Kxy(i,j) + sum[everypixel not in region i,j](LogL(ij).Gxy(ij).K'xy(ij))
   //Gxy(i, j) = exp(-((i-x)^2+(j-y)^2)/2sigma_s^2)
   //Kxy(i, j) = exp(-(LogL(i,j) - LogL(x,y))^2/2sigma_r^2)
   //K'xy(i, j) = exp(-(LogL(i, j) - LogL(x,y))^2/2sigma_r'^2)
   //Z(x,y) = sum[pixel in region](Gxy(i, j).Kxy(i, j) + sum[pixel not in region](Gxy(i, j).K'xy(i, j)
   PixelDoubleMatrix localAdaptationPixels(imageHeight, vector<double>(imageWidth, 0.0));
   double sigma_r = 0.4;
   double sigma_rr = 0.5*0.4;
   double sigma_s = (imageHeight*imageWidth)*0.04;
   int bilateralIteration = 0;
   for(int i=0; i < blocksRegions.size();i++)
   {
      for(int k=0; k < blocksRegions[i].Members.size();k++)
      {
         fprintf(stderr,"%d ",bilateralIteration);
         bilateralIteration++;
         double inRegion = 0.0;
         double inRegionZ = 0.0;
         double otherRegions = 0.0;
         double otherRegionsZ = 0.0;
         int x = blocksRegions[i].Members[k].x;
         int y = blocksRegions[i].Members[k].y;
         double logLum = LogLuminancePixels[y][x];
         for(int inReg=0; inReg < blocksRegions[i].Members.size();inReg++)
         {
            if(inReg != k)
            {
               int tmpX = blocksRegions[i].Members[inReg].x;
               int tmpY = blocksRegions[i].Members[inReg].y;
               double logLumTmp = LogLuminancePixels[tmpY][tmpX];
               double functionG = exp(-((abs(tmpX - x))^2 + (abs(tmpY - y))^2)/2*(pow(sigma_s,2.0)));
               double functionK = exp(-pow((abs(logLumTmp - logLum)),2.0)/2*(pow(sigma_r,2.0)));
               inRegion += logLumTmp*functionG*functionK;
               inRegionZ += functionG*functionK;
            }
         }
         for(int otherReg=0; otherReg < blocksRegions.size();otherReg++)
         {
            if(otherReg != i)
            {
               for(int mem=0; mem < blocksRegions[otherReg].Members.size();mem++)
               {
                  int tmpOtherX = blocksRegions[otherReg].Members[mem].x;
                  int tmpOtherY = blocksRegions[otherReg].Members[mem].y;
                  double otherLogLumTmp = LogLuminancePixels[tmpOtherY][tmpOtherX];
                  double otherFunctionG = exp(-((abs(tmpOtherX - x))^2 + (abs(tmpOtherY - y))^2)/2*(pow(sigma_s,2.0)));
                  double otherFunctionK = exp(-pow((abs(otherLogLumTmp - logLum)),2.0)/2*(pow(sigma_rr,2.0)));
                  otherRegions += otherLogLumTmp*otherFunctionG*otherFunctionK;
                  otherRegionsZ += otherFunctionG*otherFunctionK;
               }
            }
         }
         double functionZ = inRegionZ + otherRegionsZ;
         localAdaptationPixels[y][x] = (1.0/functionZ)*(inRegion + otherRegions);
         fprintf(stderr," %g\n",localAdaptationPixels[y][x]);
      }
   }



   //Local tone mapping
   // psi(L,V;p,gamma) = (L/V)^p. 





	double pY, px, py;

	int j = 0;
	for (j = 0; j < pSrc->GetHeight(); j++)
	{
		pSrc->ProgressBar(j, pSrc->GetHeight()); // You can provide progress bar
		for (int i = 0; i < pSrc->GetWidth(); i++)
		{
			pY = *pSourceData++;
			px = *pSourceData++;
			py = *pSourceData++;

			// Here you can use your transform
			// expressions and techniques...
			//pY *= dParameter; // Parameters can be used like
							  // simple variables

			// and store results to the destination image
			*pDestinationData++ = pY;
			*pDestinationData++ = px;
			*pDestinationData++ = py;
		}
	}
	pSrc->ProgressBar(j, pSrc->GetHeight());
	pDst->Convert(TMO_RGB);
	return 0;
}
