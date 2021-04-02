def Caption(img):
	if type(img) == list:
		for i in range (len(img)):
			name = pdb.gimp_image_get_name(img[i])
			height = pdb.gimp_image_height(img[i])
			drw = pdb.gimp_image_get_active_drawable(img[i])
			text_layer = pdb.gimp_text_fontname(img[i], drw, 0, height-25, name, 0, False, 20.0, 0, "Arial")
			pdb.gimp_text_layer_set_color(text_layer, "GRAY")
			pdb.gimp_floating_sel_to_layer(text_layer)
	else:
		background = pdb.gimp_context_get_background()
		name = pdb.gimp_image_get_name(img)
		height = pdb.gimp_image_height(img)
		drw = pdb.gimp_image_get_active_drawable(img)
		text_layer = pdb.gimp_text_fontname(img, drw, 0, height-25, name, 0, False, 20.0, 0, "Arial")
		pdb.gimp_text_layer_set_color(text_layer, "GRAY")
		pdb.gimp_floating_sel_to_layer(text_layer)
	
