inherit"room/room";
reset (arg) {
if (arg) return;
set_light(1);
short_desc="Patience Workroom";
long_desc="This is the wonderous workroom of the Great wizard Patience.\n"+
          "All the gadgets in here look very hi-tech so you should becareful\n"+
          "what you touch!\n";
dest_dir=({
"/room/adv_guild","guild",
"/room/church","church",
"/players/helenette/workroom","helenette",
"/obj/tick","tick",
"/room/post","post",
         });
return 1;
}
