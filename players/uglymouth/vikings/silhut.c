/* Sil's messy hut */
/* Galadriel 08-DEC-93: commented replace program, was buggy */
/* G: doesnt work together with sil cloning code in reset */
inherit "room/room";
object sil;

void reset(int arg)   {

   if(!(sil=present("sil")) || !living(sil))
   transfer(clone_object("/players/uglymouth/vikings/monsters/sil"),this_object());
   if(arg) return 0;

   set_light(1);
   short_desc="You're in Sil's messy hut";
   long_desc="This hut is full of junk that Sil found on the beach \n"
           + "and it all looks worthless. It's stuffed to the ceiling. \n"
           + "You can't imagine how Sil can live in this mess. \n";
   dest_dir=({"/players/uglymouth/vikings/dunes_n","out", });
   items=({"junk","Real junk. You would be ashamed of yourself if you had to show it in a shop", });
/* Galadriel */
/*   replace_program("room/room"); */
   }
