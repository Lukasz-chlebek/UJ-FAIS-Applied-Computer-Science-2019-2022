def Gamma(img, gam, whichopt):
	if type(img) == list:
		for i in range( len(img)):
			if whichopt:
				drw = pdb.gimp_image_get_active_drawable(img[i])
				pdb.gimp_drawable_levels(drw, 0, 0, 1, False, gam, 0, 1, False)
			if not whichopt:
				temp = pdb.gimp_image_get_active_drawable(img[i])
				list1 = img[i].layers
				for j in range (len(list1)):
					pdb.gimp_image_set_active_layer(img[i],list1[j] )
					lay = pdb.gimp_image_get_active_drawable(img[i])
					pdb.gimp_drawable_levels(lay, 0, 0, 1, False, gam, 0, 1, False)
				pdb.gimp_image_set_active_layer(img[i], temp)
	else:
		if whichopt:
			drw = pdb.gimp_image_get_active_drawable(img)
			pdb.gimp_drawable_levels(drw, 0, 0, 1, False, gam, 0, 1, False)
		if not whichopt:
			temp = pdb.gimp_image_get_active_drawable(img)
			list1 = img.layers
			for j in range (len(list1)):
				pdb.gimp_image_set_active_layer(img,list1[j] )
				lay = pdb.gimp_image_get_active_drawable(img)
				pdb.gimp_drawable_levels(lay, 0, 0, 1, False, gam, 0, 1, False)
			pdb.gimp_image_set_active_layer(img, temp)
