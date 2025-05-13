inherit"obj/treasure";
reset(arg) {
    if (arg) return;
    set_id("brochure");
    set_short("Dragon Airways Brochure");
    set_long(
      "------------------------------------------------------------\n"+
      "|           DRAGON AIRWAYS FLIGHT SCHEDULE                 |\n"+
      "|           Flights Arrive about every minute.             |\n"+
      "|           Flights Cost 500 coins !!                      |\n"+
      "|                                                          |\n"+
      "| Port 1 - Near Warlord's Castle                           |\n"+
      "| Port 2 - Under Construction                              |\n"+
      "| Port 3 - Near Rope Bridge                                |\n"+
      "| Port 4 - Near Sea World                                  |\n"+
      "| Port 5 - Near Tree-city                                  |\n"+
      "|                                                          |\n"+
      "| More destinations to be added in the future !!           |\n"+
      "| Look for them !!                                         |\n"+
      "____________________________________________________________\n\n");
    set_weight(1);
    set_value(0);
}
