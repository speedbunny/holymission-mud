inherit "/obj/thing";
#define TP    this_player()
#define TPN   TP->query_name()
#define ENV   environment

static int is_open = 0;
static int is_closed = 1;

void set_descs() {

  set_long("");
  set_short("");
}

int query_is_closed() {

  return is_open;
}

void set_short(string sh) {

  if(is_open)
    {short_desc = "A book";}
  if(is_closed)
    {short_desc = "A book";}
}

void set_long(string long) {

  if(is_open)
    long_desc="A leatherbound book.\n";
  else
    long_desc="A leatherbound book.\n";
}

void reset(int arg) {
  ::reset(arg);

  if(arg) return;

  set_name("book");
  set_alias("book");
  set_descs();
  set_can_get(1);
  set_weight(1);
  set_value(100);
}

void init() {
  ::init();

  add_action("_read","read");
  add_action("_open","open");
  add_action("_close","close");
}

int _open(string str) {

  switch(str) {
    case "book" :
      if(is_open) {
        write("But the book is already open!\n");
        return 1;
      }
        is_open = 1;
      write("You open the book\n");
      return 1;
    case "leaflet" :
    case "pamphlet" :
      notify_fail("Open what?\n");
      return 0;
    default :
      notify_fail("Open what?\n");
      return 0;
  }
}

int _read(string str) {

  switch(str) {
    case "book" :
      if(is_open) {
        write("You cannot read this book, it is in a language you don't understand! \n" +
               "However, you notice someone has cleverly glued a handwritten note in \n" +
               "the front cover...\n" );
        say(TPN + " cannot understand this book.\n");
        return 1;
      }
      else {
        write("You cannot read a closed book.\n");
        return 1;
      }
    case "leaflet" :
    case "note" :
        write("You read the leaflet glued inside the book\n\n");
        say(TPN + "reads the leaflet inside the book.\n");
        this_player()->more("/players/redsexy/jedi/objects/note.txt");
        return 1;
    default :
      notify_fail("Read what?\n");
      return 0;
  }
}

int _close(string str) {

  switch(str) {
    case "book" :
      if(!is_open) {
        write("The book is already closed.\n");
        return 1;
      }
      is_open = 0;
      write("You close the book\n");
      return 1;
    default :
      notify_fail("Close what?\n");
      return 0;
  }
}

