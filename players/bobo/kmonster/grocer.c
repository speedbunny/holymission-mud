inherit "obj/monster";

reset(arg) {
::reset(arg);
if (arg) return;
 set_name("grocer");
 set_alias("man");
 set_short("The grocer");
 set_long("He's the owner of this shop. He can sell you almost everything.\n");
 set_race("human");
 set_level(15);
 set_size(3);
 set_al(100);
}

 

