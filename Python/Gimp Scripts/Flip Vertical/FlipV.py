def FlipV(img):
	if type(img) == list:
		for i in range (len(img)):
			pdb.gimp_image_flip(img[i], 1)
	else:
		pdb.gimp_image_flip(img, 1)
