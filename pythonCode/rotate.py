import cv2

inputImage = cv2.imread("../assets/putin.jpg")

center = (inputImage.shape[1]/2, inputImage.shape[0]/2)
rotationAngle = -30
scale = 1

roationMatrix=cv2.getRotationMatrix2D(center, rotationAngle, scale)
size = (inputImage.shape[1], inputImage.shape[0])

result = cv2.warpAffine(inputImage, roationMatrix, size)

cv2.namedWindow("image", cv2.WINDOW_NORMAL)
cv2.namedWindow("result", cv2.WINDOW_NORMAL)

cv2.imshow("image", inputImage)
cv2.imshow("result", result)

cv2.waitKey(0)
cv2.destroyAllWindows()