inherit"obj/monster";
object durandal,shield,platemail,gauntlets,helmet,cloak;

reset(arg){
    ::reset(arg);
    if (arg) return 1;
    set_name("Roland the Paladin");
    set_race("human");
    set_gender(1);
    set_alias("roland");
    set_short("Roland the Paladin");
    set_long("Roland the Paladin, chivalrous knight of King Charlemagne.\n");
    set_level(20);
    add_money(400+random(500));
    set_whimpy();
    set_al(50000);
    durandal=clone_object("/players/colossus/weapons/durandal");
    move_object(durandal,this_object());
    init_command("wield durandal");
    platemail=clone_object("/players/colossus/armors/rplate");
    move_object(platemail,this_object());
    command("wear platemail");
    helmet=clone_object("/players/colossus/armors/rhelmet");
    move_object(helmet,this_object());
    command("wear helmet");
    shield=clone_object("/players/colossus/armors/rshield");
    move_object(shield,this_object());
    command("wear shield");
    cloak=clone_object("/players/colossus/armors/rcloak");
    move_object(cloak,this_object());
    command("wear cloak");
    gauntlets=clone_object("/players/colossus/armors/rgauntlets");
    move_object(gauntlets,this_object());
    command("wear gauntlets");
}
