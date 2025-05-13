inherit "obj/monster";
#include "/players/brainsprain/spiral/spidef.h"
int randomizer;
void reset(int arg) {
    ::reset(arg);
if(arg) return;
    set_name("goblin groveler");
    set_race("goblin");
    set_gender(1);
    set_alias("goblin");
    set_alt_name("goblin");
    set_short("A groveling goblin");
    randomizer=(random(6));
    if (randomizer==1 || randomizer ==0)  {
      set_long(
"A groveling goblin, a pathetic creature pleading for his life.  The "+
"bruises on his back, as well as his ragged clothing, indicate that he has been "+
"severely beaten.  A myriad of cuts and bruises cover his face.  He is "+
"practically naked and very dirty.\n");
  }
     if (randomizer==3 || randomizer == 2){
            set_long(
"A goblin sits before you, crying into his hands.  His bleary eyes are filled "+
"with tears.  The tattered remnants of his clothing hang from his shoulders "+
"whip marks cover his back and cheeks and blood runs freely from the corner "+
"of his mouth.\n");
          }
    if (randomizer==4 || randomizer==5){
            set_long(
"A small goblin sits here shaking like a leaf.  His hair is caked to his head "+
"by sweat.  It is covered in dried blood and smells like urine.  A wooden "+
"pole sticks out of his side about midway up his chest.  Blood and puss spill "+
"out of the wound.\n");
          }
    set_level(12);
    set_al(-40);
    load_chat(2, ({
"Goblin Groveler says: Please spare me.\n",
"Goblin Groveler says: I have done nothing wrong.\n"
}));
move_object(clone_object(si+"/rusty_dagger.c"), TO);
init_command("wield dagger");
}
