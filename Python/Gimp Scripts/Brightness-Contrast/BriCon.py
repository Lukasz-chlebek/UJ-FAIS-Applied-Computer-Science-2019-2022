def BriCon(img, b, c, whichopt):
	if type(img) == list:
		for i in range ( len(img)):
			if whichopt:
				drw = pdb.gimp_image_get_active_drawable(img[i])
				pdb.gimp_drawable_brightness_contrast(drw, b, c)
			if not whichopt:
				temp = pdb.gimp_image_get_active_drawable(img[i])
				list_lay = img[i].layers
				for j in range (len(list_lay)):
					pdb.gimp_image_set_active_layer(img[i],list_lay[j] )
					lay = pdb.gimp_image_get_active_drawable(img[i])
					pdb.gimp_drawable_brightness_contrast(lay, b, c)
				pdb.gimp_image_set_active_layer(img[i], temp)
	else:
		if whichopt:
			drw = pdb.gimp_image_get_active_drawable(img)
			pdb.gimp_drawable_brightness_contrast(drw, b, c)
		if not whichopt:
			temp = pdb.gimp_image_get_active_drawable(img)
			list_lay = img.layers
			for j in range (len(list_lay)):
				pdb.gimp_image_set_active_layer(img,list_lay[j] )
				lay = pdb.gimp_image_get_active_drawable(img)
				pdb.gimp_drawable_brightness_contrast(lay, b, c)
			pdb.gimp_image_set_active_layer(img, temp)
