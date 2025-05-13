#define SAY(x) tell_room(environment(),x)
inherit "obj/monster";

reset(a) 
{
    ::reset(a);
    if (a) return 0;
    set_name("leila");
    set_short("Leila the elf");
    set_long("Leila the Sheriff's ...\nShe is very nice and looks happy.\n");
    set_gender(2);
    set_race("elf");
    set_size(3);
    set_level(10);
    set_wc(13);
    set_ac(10);
    move_object(clone_object("/players/goldsun/nottingham/obj/dress"),this_object());
    init_command("wear dress");
}


