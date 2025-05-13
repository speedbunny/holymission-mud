inherit "room/room";

void reset(int arg) {

  if(arg) return;

  set_light(1);
  short_desc="A meadow of blooming flowers";
  long_desc="The flowers which bloom in this meadow take on all colours " +
            "and shapes.  Most are yellow, white, and purple, but here and " +
            "there a vivid blue or flaming scarlet catch your eye.  Most " +
            "of the flowers appear to be herbs; varieties of thyme, " +
            "lady's mantle, aconite, and bergamot.  There is a lovely " +
            "scent in the air from the fragrant blossoms.\n";

  dest_dir=({"/players/emerald/lakmir/meadow2","north",
             "/players/emerald/lakmir/southgate","east",
             "/players/emerald/lakmir/pasture","west"
           });

  smell="The scent of the thyme is particularly lovely";

  items=({"flowers","There are flowers in all colours.  They smell wonderful",
          "meadow","A flat area of grass and flowers",
          "herbs","Plants identified as having medicinal properties",
          "thyme","A low-growing herb with a wonderful scent",
          "bergamot","It is tall with a bright red flower",
          "lady's mantle","A small plant with yellow flowers",
          "aconite","The deadly blue monkshood",
        });

  ::reset();
  replace_program("/room/room");

}
