inherit "obj/monster";

reset(arg){
::reset(arg);

  if(arg) return;

	set_name("kid");
	set_short("Trog children");
	set_race("trog");
	set_alias("trog");
	set_gender(1+random(1));
        set_long("A trog child. Young and helpless.\n");
	set_level(3);
     return 1;
	}

