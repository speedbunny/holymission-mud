inherit "/obj/treasure";

reset(arg){
 if (arg) return;
 set_id("scroll");
 set_read("()-------  ------------------)\n"+
          " \\       \\/              N  |\n"+
          " /                      W+E/\n"+
          " \\     To the n__th      S \\\n"+
          "  |    of She <  > forest  |\n"+
          "  |    on the h\\/  is a    |\n"+
          "  \\    plain with small    /\n"+
          "   \\   entrance to the    /\n"+
          "   <   cave. We sacrifice/\n"+
          "  /    there to mighty G/\n"+
          " ()---------------------\n");
 set_short("A scroll");
 set_long("An old scroll.\n");
 set_weight(1);
 set_value(2);
 }
