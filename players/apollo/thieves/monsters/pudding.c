
/* Apollo fixed desc and attack desc - 02/02/95 */

inherit "obj/monster";
#include "/players/apollo/thieves/objs/rnd_treas.h"

#define TO        this_object()
#define CO(x)     move_object(clone_object(x),TO)

int i,j;
object ob2, sh;

int attack() {

  object ob, pers;

  if (::attack()) {   
    if (random(2))
      ::attack();
    if (j<0 || j>2)
      j=2;
    pers=TO->query_attack();
    ob = pers->query_wielded();
    if (objectp(ob)) {
      switch(j) {
        case 2 : tell_object(pers,"YOU HAVE LOST YOUR WEAPON!\n");
                 break;
        case 1 : tell_object(pers,"YOUR WEAPON HAS BEEN DISSOLVED!\n");
                 break;
        default : { tell_object(pers,"YOUR WEAPON HAS BEEN DESTROYED!!!\n");
                    write_file("/players/kryll/log/pud_eat",pers->query_real_name()+
                               "    "+ob->query_name()+"\n");
                    destruct(ob);
                    break; }
        }
    j--;
    }
    if (!random(4)) {
      tell_object(pers,"Acid burns through your flesh!\n");
      pers->hit_player((50+random(21)),7,4);
    }
  }
}


void reset(int arg) {

  ::reset(arg);
  if (!arg) {
    j=2;

    set_name("black pudding");
    set_alias("pudding");
    set_race("slime");
    set_size(2);
    set_level(15);
    set_short("Black Pudding");
    set_long("A large, black gelatinous ooze is slowly dissolving any \n" +
	"remains laying around on the ground of the sewers. You \n" +
	"believe it thinks you might be a tastier delight.\n");
    set_wc(10);
    set_ac(10);
    set_hp(400+random(200));
    set_al(-200);
    set_no_steal(1);
    set_aggressive(0);
    add_money(4000+random(1001));
/* Jun 24 1997 Kryll - took out my stuff, since not in game.
   Also, don't clone wizard's hat. Should only be from padrone's
   sh = clone_object("/players/kryll/obj/pudding_shad");
    sh->start_shadow(this_object(),0,"pudding_shad");
    ob2=clone_object("/players/ted/items/bag_of_holding");
       move_object(clone_object("/players/padrone/obj/wizardshat"), ob2);       
*/
    ob2=clone_object("/players/ted/items/bag_of_holding");
    for(i=0;i<10;i++)
       move_object(clone_object(rnd_treas()),ob2);
    move_object(ob2,TO);
  }
}
