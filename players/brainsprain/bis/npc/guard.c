inherit "obj/monster";
#include "/players/brainsprain/bis/bisdef.h"
void reset(int arg){
    ::reset(arg);
    set_name("guard");
    set_race("human");
    set_gender(1);
    set_alias("man");
    set_alt_name("castle guard");
    set_short("A Castle Guard");
            set_long(
"This massive human is covered in armour.  He stands over six feet tall "+
"and has wide shoulders.  He hefts his longsword as if it were a toothpick. "+
"He has sworn his life to protect this keep from all enemies.\n");
    set_level(15);
    set_hp(400);
    set_al(100);
    set_ac(4);
    set_wc(14);

    move_object((clone_object(bi+"/longsword.c")),this_object());
    move_object((clone_object(bi+"/gauntlets.c")),this_object());
    move_object((clone_object(bi+"/boots.c")),this_object());
    move_object((clone_object(bi+"/shield.c")),this_object());
    move_object((clone_object(bi+"/helmet.c")),this_object());
    move_object((clone_object(bi+"/platemail.c")),this_object());
    move_object((clone_object("/players/brainsprain/bis/quest/qmed.c")),TO);

    init_command("wield sword");
    init_command("wear shield");
    init_command("wear gauntlets");
    init_command("wear boots");
    init_command("wear helmet");
    init_command("wear platemail");
    init_command("wear medallion");
   }
