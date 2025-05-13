void make(){
    object temp, there1, there2, boat, boat1, boat2, bell;

    temp=clone_object("/obj/treasure");
    move_object(temp, "/players/colossus/mearth/shire/pier2");
    there1=environment(temp);
    boat1=present("boat", there1);
    move_object(temp, "/players/colossus/mearth/shire/island1");
    there2=environment(temp);
    boat2=present("boat", there2);
    destruct(temp);
    if(!boat1 && !boat2){
	boat=clone_object("/players/colossus/mearth/shire/real_boat");
	move_object(boat, there1);
    }
    bell=present("bell", there1);
    if(!bell){
	bell=clone_object("/players/colossus/mearth/shire/bell00");
	move_object(bell, there1);
    }
}
