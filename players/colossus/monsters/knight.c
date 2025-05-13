inherit"obj/monster";
object mace,hauberk,helmet,shield;
reset(arg){
    ::reset(arg);
    set_name("knight");
    set_short("A French knight");
    set_long("A noble knight of France.\n");
    set_level(20);
    set_gender(1);
    set_race("human");
    set_ep(10000000);
    set_al(5000);
    set_wc(12);
    add_money(300+random(250));
    mace=clone_object("/players/colossus/weapons/mace");
    move_object(mace,this_player());
    init_command("wield mace");
    hauberk=clone_object("/players/colossus/armors/hauberk");
    move_object(hauberk,this_object());
    command("wear hauberk");
    helmet=clone_object("/players/colossus/armors/rhelmet");
    move_object(helmet,this_object());
    command("wear helmet");
    shield=clone_object("/players/colossus/armors/rshield");
    move_object(shield,this_player());
    command("wear shield");
}
