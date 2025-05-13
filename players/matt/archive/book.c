#include "/players/matt/definitions"

id(arg) {
  return arg == "book" || arg == "old book";
        }

short() {
  return "An old book";
        }

long() {
  write("An extremely old book with a worn black cover and yellowed\n");
  write("pages, this tome has mystical Runes upon it, traced in silver.\n");
       }

get() { return 1; }
drop() {
  write("You drop the book.\n");
  say(TP->NAME + " drops " + TP->POS + " book.\n");
  TELLR(ENV(TP), "As it hits the ground, the pages spill out and crumble.\n");
  destruct(TO);
  return 1;
       }

init() {
  add_action("read", "read");
       }

read(arg) {
  object spec;
  if(id(arg)) {
    spec = present("spectacles", TP);
    if(spec && spec->query_worn()) {
      write("Most pages of the old book are tattered beyond recognition,\n");
      write("but one page seems magically preserved. It says:\n");
      write("   \"...and once the four Elements are thus contained,\n");
      write("the Forger God, Vulcanus, may be summoned to a secluded\n");
      write("place of power. If properly cast, the Summon spell will\n");
      write("allow Vulcanus to surge the final Element, Power, into\n");
      write("the four prisms and rejoin them into the One.\n");
      write("    Careful preparation of the site is crucial. First a\n");
      write("circle must be drawn there according to the diagram\n");
      write("which follows here, with no mistakes. The smallest of\n");
      write("errors will allow Vulcanus' wrath to escape.\n");
      write("    Finally, when the circle is drawn, summon the Forger,\n");
      write("carefully chanting the words that follow...\"\n\n");
      return 1;
                                  }
    write("You cannot understand the ancient language.\n");
    return 1;
              }
          }

query_weight() { return 1; }
