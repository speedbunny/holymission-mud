inherit "obj/thing";

#include "/players/topaz/defs.h"

string file;

void reset(int arg) {
  ::reset(arg);
  if(!arg) {
  set_name("clipboard");
  set_short("Topaz's clipboard");
  set_long("This is Topaz's clipboard of things to do.\n"
    + "It's three commands are:\n" +
      "    lookclip <page#>\n" +
      "    write <page#> <note>\n" +
      "    erase <page#>\n" +
      "However, it won't work for anyone but Topaz.\n");
  }
}

void init() {
  ::init();
   add_action("_lookclip","lookclip");
   add_action("_write","write");
   add_action("_erase","erase");
}


_lookclip(str) {
  if(TP->query_real_name() !="topaz") {
    write("What are you looking at Topaz's clipboard for?!");
    destruct(TO);
    return 1;
  }
  else {
    if(str=="page1" || str=="page 1") {
    cat("/players/topaz/logs/clipboard/page1.txt");
    return 1;
    }
    if(str=="page2" || str=="page 2") {
    cat("/players/topaz/logs/clipboard/page2.txt");
    return 1;
    }
    if(str=="page3" || str=="page 3") {
    cat("/players/topaz/logs/clipboard/page3.txt");
    return 1;
    }
    if(str=="page4" || str=="page 4") {
    cat("/players/topaz/logs/clipboard/page4.txt");
    return 1;
    }
    else {
    write("That page doesn't exist.  Try a page# from 1 - 4.\n");
    return 1;
    }
  }
}

_erase(str) {
  if(TP->query_real_name() != "topaz") {
    destruct(TO);
    return 1;
  }

  if(!str) {
    write("You must specify a page to erase.\n");
    return 1;
  }
  else {
    if(str=="page1" || str=="page 1") {
      return 1;
    }
    if(str=="page2" || str=="page 2") {
      return 1;
    }
    if(str=="page3" || str=="page 3") {
      return 1;
    }
    if(str=="page4" || str=="page 4") {
      return 1;
    }
    else {
      write("Try writing to a page number between 1 and 4.\n");
      return 1;
    }
  }
}

int _write(string str) {
string pag;
string mes;
  if(sscanf(str, "%s %s", pag, mes) == 2) {
  if(TP->query_real_name() != "topaz") {
    destruct(this_object());
    return 1;
  }

  if(!pag) {
    write("You must specify a page to write on.\n");
    return 1;
  }
  else {
    if(pag=="page1" || pag=="page 1") {
      file="/players/topaz/logs/clipboard/page1/txt";
      write_file(file, str + "\n");
      return 1;
    }
    if(pag=="page2" || pag=="page 2") {
      file="/players/topaz/logs/clipboard/page2.txt";
      write_file(file, str + "\n");
      return 1;
    }
    if(pag=="page3" || pag=="page 3") {
      file="/players/topaz/logs/clipboard/page3.txt";
      write_file(file, str + "\n");
      return 1;
    }
    if(pag=="page4" || pag=="page 4") {
      file="/players/topaz/logs/clipboard/page4.txt";
      write_file(file, str + "\n");
      return 1;
    }
    else {
      write("There is no page with that number.\n" +
            "Please try a page number from 1 to 4.\n");
      return 1;
    }
  }
  }
}
