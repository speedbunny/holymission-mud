/* Do any name definitions here */

inherit "room/room";
object ob,x;
/* This procedure is called every hour at the moment. The first
time it is called with the arg = 0, after that arg is always 1 */

reset(arg) {
    if (!arg) {
    /* first we need to decide on light level */
    set_light (1);
    /* then the brief description */
    short_desc = "Darastor's 'Better Than Life' game terminal";
    /* now the long standard room description */
    long_desc = "You put on the terminal headset for the game - you feel the"
+               " electrical impulses from the machine probing into your mind"
+               ". You type 'RUN' on the keyboard and the machine begins to"
+               " hum. As the machine gets a hold of your fantasies you are"
+               " transported to another place....\n\n\n"
+               "You are at that party you always wanted to give. The room is"
+               " identical to the dining hall at Buckingham Palace. Sitting"
+               " on your left is Julius Caesar, on your right is Napoleon"
+               " Bonaparte and opposite you is Albert Einstein. The four of"
+               " you are laughing about the Monopoly Board pub crawl of"
+               " London you did last night. On the table is a menu of the"
+               " meal being served.\n"
   ;

    dest_dir=({
             "/players/darastor/workroom.c","out",
    });

   /* item descriptions here */
    items=({
    "caesar","One of the" + " most famous Roman Emperors ever. He even had a" 
+            " Shakespeare play written about him. The play did not, however"
+            " mention the sheep he woke up next to this morning",
    "napoleon","The one-time Emperor of France. He was doing pretty well"
+              " for quite a while. Shame about Waterloo really. He is"
+              " wearing a traffic cone on his head at the moment. Must have"
+              " picked it up last night",
    "einstein","The greatest physicist of the 20th century. Shame he gave"
+              " the world the atom bomb. Apparently the mayor of Hiroshima"
+              " was pretty impressed though. He would be less impressed at"
+              " the state Al was in this morning though",
    });
   /* Properties of room here */
    property = ({"no_sneak","no_steal","no_teleport"
    });

   /* set smell here */
    smell = "This room smells of gorgeous food - and you're eating it";
  }
  }
init () {
  ::init();
  x=first_inventory(this_object());
  do {
             if (!x) break;
             if (x->query_npc()) {
                  write(" You get the feeling there is an uninvited guest" 
                       +  "present.\n");
                  break;
		}
             else {
                  write(" All is well at this party.\n");
                  break;
                }
	   }
     while(x=next_inventory(x));
  }
