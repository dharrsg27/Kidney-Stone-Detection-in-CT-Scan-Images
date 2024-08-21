# Kidney-Stone-Detection-in-CT-Scan-Images
Kidney stones, also called renal calculi, are hard deposits made of minerals and salts that form inside the kidneys. Kidney stones are caused by many factors, such as diet, medical conditions and the supplements or medications taken. Kidney stones can affect any parts of the urinary tract, which includes the kidneys, bladder and urethra. Stones usually form when the urine becomes too concentrated, which causes minerals to crystallize and stick together. Kidney stones don’t cause permanent damage if they are diagnosed early, however, if stones form deep in the urinary tract, surgery may be needed.

Over the past few years, many imaging tests, like ultrasound, CT and MRI are used to diagnose kidney stone disease. However, CT scans are the most commonly used diagnostic test for kidney stones because of the time taken, cost, and information gained. However, a challenge of kidney stone diagnosis on CT scans is that segmentation of the image is quite challenging because of the complicated structures of interest in abdomen CT. Therefore, the way in which the image is processed plays a crucial role in improving the accuracy of the detection of kidney stones. 

This project aims to create a GUI application with Qt Creator which allows users to easily upload a kidney CT scan image and will then try to segment and detect kidney stones in the images through a robust series of image processing techniques, which includes: 

1. Median Filtering
   - Median filtering is a common preprocessing technique used to remove noises in an image and makes the image smoother in appearance. The median filter works by first making a defined size of kernel which will go through every area of the image.
   - On every area of the image, it will look into the pixels contained in the area, and it will sort the pixel from smallest to largest. Afterwards, it will find the median value, and thus, the output will be the median value.
2. K-Means Clustering
   - K-Means Clustering is a powerful image segmentation technique. It is an unsupervised algorithm and it is used to segment the interest area from the background. It primarily clusters, or partitions the given data into K-clusters based on the K-centroids, meaning that it will place each data point to the nearest centroid.
   - K-Means Clustering aims to find certain groups based on similarities in the data with the number of groups represented by K, which in this case would then group the image into K distinct colors.
3. Thresholding
   - Thresholding is an image segmentation technique that can be used to create a binary image. Thresholding works by defining a threshold value, in which any value below the threshold will be returned as 0 or black, and any value above the threshold will be returned as 1 or white.
   - This is used after K-Means Clustering, because it will make it easier to detect the extreme intensities (black and white).
5. Erosion
   - Erosion is a morphological operation that helps in shrinking images. This is useful in the context of this project because after thresholding, there may be some small white-colored noises in the background of the image, therefore, it will shrink the small noises and remove it.
7. Dilation
   - Dilation is a morphological operation that helps in enlarging images. The problem with erosion is that although it helps in removing the noises, erosion also causes the larger area of interest to shrink and loses some important pixel data.
   - Therefore, dilation helps in enlarging the image, specifically the area of interest, thus restoring back the pixel data, while also keeping the noises removed.
9. Contouring
   - Contours are curves joining all continuous points along a boundary that have the same color and intensity, thus helping in making an outline of the region.
   - In this project, contouring is used to detect the spine, which is a large white region in the CT scan, and some other small white regions that are still left after dilation.
   - Therefore, this has to be removed by first finding all the contours in the image. Afterwards, a bounding rectangle was made around each contour. Then, it will compute the area of each bounding rectangle and it will look for the area that is greater than or smaller than the specified area.
   - The rectangle will be filled with black color to seemingly remove those contours which are greater than the specified area.
   - Afterwards, the contours after removing the areas are found, then filled with a color to mark it, and are drawn into a copy of the original image. The final output of the image will show where the kidney stones are, and will be marked with the color green.
