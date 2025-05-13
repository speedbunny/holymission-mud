inherit "obj/monster";
#include "/players/brainsprain/bis/bisdef.h"
void reset(int arg){
    ::reset();
    set_name("Sheep");
    set_race("sheep");
    set_gender(1);
    set_alias("monster");
    set_short("Sheep");
            set_long(
"This poor little sheep looks bewildered, almost as if he does not quite "+
"fit into his body.  He bleats soulfully as he sees you.  There are "+
"several grass stains on his face.  He looks like he needs a trim.\n");
    set_level(1);
    set_hp(50);
    set_al(-40);
    set_ac(0);
    set_wc(5);
}
