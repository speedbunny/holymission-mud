inherit "room/room";

reset(arg) {
  ::reset(arg);
  if(!arg) {

     set_light(1);
     short_desc = "Cell";
     long_desc = 
   "You have entered no man's land. If you are here then you must fight, \n"+ 
   "if you want to live.  This is the proving ground for Gareth's \n"+
   "nightmarish creatures, so you got to ask yourself 'what am I doing here?\n"+ 
   "Be thankful you have not stumbled here when something else was here.\n";
     dest_dir = ({
  
     });

}
}
