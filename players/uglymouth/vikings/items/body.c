/* the body of the village priest*/
inherit "obj/corpse";
object note;

void reset(int arg) {
   ::reset(arg);

   if(!arg) {
      set_name("the village priest");
      set_race("human");

      note=clone_object("/players/uglymouth/vikings/items/viknote");
      transfer(note,this_object());
      }
   }
