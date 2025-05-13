	inherit "room/room";

	reset(arg) {
	::reset(arg);
	if(arg) return;

	set_light(1);
	short_desc = "Kobka";
	long_desc = 
		"Vitam Ta velky Titan. Dakujem ze si poctil moju miestnost tvojou navstevou.\n"
		"Som rad ze Ta ten skurveny mat-fyz nezdebilnel natolko, aby si si nenasiel cas\n"
		"na HOLY MISSION. Urcite Ti uz z tohe statocne drbe. Viem si to predstavit.\n"
		"Ved uz i ta linka z Blavy je taka kockata. Dufam, ze si dobre oddychnes a\n"
		"coskoro sa opat budes muoct rozvalovat v tejto izbietke.\n";

	dest_dir = ({"players/titan/workrooms","south"});
}

