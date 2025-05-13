/* Magic Marker, coded by Matt SEP-02-04 */

/* Macros */
#define REQLEVEL    30
#define TP          this_player()
#define TO          this_object()
#define NAME        query_name()
#define ENV         environment
#define FN          file_name

/* Global variables */
status lightlev;
object mark;
object altmark;

/* Function prototypes */
public int id(string arg);
public string short();
public void   long();
public int    get();
public int    drop();
public void   init();
public int    do_mhelp(string arg);
public int    do_mmark(string arg);
public int    do_mmarkalt(string arg);
public int    do_mcall(string arg);
public int    do_mdump(string arg);
public int    do_mstat(string arg);
public int    do_mlight(string arg);
public int    do_mfind(string arg);
public int    do_mdest(string arg);
public int    do_mdestall(string arg);
public int    do_mmove(string arg);
public int    do_mcode(string arg);
public int    do_L(string arg);
public int    do_I(string arg);
static int    move_mark(object new);
static int    move_altmark(object new);
static string mname(object obj);
static void   print_inv(object *inv, int sizeinv);
public string query_auto_load();

/* Function definitions */
public int id(string arg) { return arg == "tool" || arg == "marker"; }
public string short() {
  return "A magic marker" + (lightlev ? " (glowing)" : "");
}
public void long() {
  write("This is the ultimate tool for wizards, created by Matt.\n");
  write("Type \"mhelp\" for more details.\n");
}

public int get() { return 1; }
public int drop() { return 1; }

public void init() {
  if(TP->query_level() < REQLEVEL) {
    write("The marker vanishes as you touch it.\n");
    destruct(TO);
  }

  add_action("do_mhelp",    "mhelp");
  add_action("do_mmark",    "mmark");
  add_action("do_mmarkalt", "mmarkalt");
  add_action("do_mcall",    "mcall");
  add_action("do_mdump",    "mdump");
  add_action("do_mstat",    "mstat");
  add_action("do_mlight",   "mlight");
  add_action("do_mfind",    "mfind");
  add_action("do_mdest",    "mdest");
  add_action("do_mdestall", "mdestall");
  add_action("do_mmove",    "mmove");
  add_action("do_mcode",    "mcode");
  add_action("do_L",        "L");
  add_action("do_I",        "I");
}

public int do_mhelp(string arg) {
  if(arg) return 0;
  write("Marker commands are:\n");
  write(" - mmark <liv>:    Marks living named <liv>\n");
  write(" - mmark <obj>:    Marks object named <obj>\n");
  write(" - mmark <num>:    Marks object #<num> in mark\n");
  write(" - mmark env:      Makrs environment of current mark\n");
  write(" - mmarkalt:       Same usage as mmark, marks alternate object\n");
  write(" - mcall <f> <a> : Calls function <f> with arg <a> in mark\n");
  write(" - mdump:          Dumps list of mark's inventory\n");
  write(" - mstat:          Shows status of marker\n");
  write(" - mlight:         Displays light level of your environment\n");
  write(" - mlight <num>:   Changes marker's light level to <num>\n");
  write(" - mfind <liv>:    Shows the environment of living <liv>\n");
  write(" - mfind <obj>:    Shows the environment of object <obj>\n");
  write(" - mdest:          Destructs current mark\n");
  write(" - mdestall:       Destructs all objects contained in mark\n");
  write(" - mmove:          Moves mark to alternate object\n");
  write(" - mcode:          Calls a fragment of LPC code\n");
  write(" - L:              Enhanced look command\n");
  write(" - I:              Enhanced inventory command\n");
  return 1;
}

public int do_mmark(string arg) {
  int num;
  int sizeinv;
  object m;
  object *inv;

  if(m = find_living(arg)) return move_mark(m);
  if(m = find_object(arg)) return move_mark(m);
  if(sscanf(arg, "%d", num)) {
    if(!mark) {
      write("No mark found.\n");
      return 1;
    }
    sizeinv = sizeof(inv = all_inventory(mark));
    if((num < 1) || (num > sizeinv)) {
      write("Bad object number.\n");
      return 1;
    }
    return move_mark(inv[num - 1]);
  }
  if(arg == "env") {
    if(!mark) {
      write("No mark found.\n");
      return 1;
    }
    if(!ENV(mark)) {
      write(capitalize(mname(mark)) + " has no environment.\n");
      return 1;
    }
    return move_mark(ENV(mark));
  }
  write("Cannot find " + arg + ".\n");
  return 1;
}

public int do_mmarkalt(string arg) {
  int num;
  int sizeinv;
  object m;
  object *inv;

  if(m = find_living(arg)) return move_altmark(m);
  if(m = find_object(arg)) return move_altmark(m);
  if(sscanf(arg, "%d", num)) {
    if(!altmark) {
      write("No alt mark found.\n");
      return 1;
    }
    sizeinv = sizeof(inv = all_inventory(altmark));
    if((num < 1) || (num > sizeinv)) {
      write("Bad object number.\n");
      return 1;
    }
    return move_altmark(inv[num]);
  }
  if(arg == "env") {
    if(!altmark) {
      write("No alt mark found.\n");
      return 1;
    }
    if(!ENV(altmark)) {
      write(capitalize(mname(altmark)) + " has no environment.\n");
      return 1;
    }
    return move_altmark(ENV(mark));
  }
  write("Cannot find " + arg + ".\n");
  return 1;
}

public int do_mcall(string arg) {
  int intarg;
  string func;
  string strarg;

  if(!mark) {
    write("No mark found.\n");
    return 1;
  }
  if(!arg) {
    write("Call what function?\n");
    return 1;
  }
  if(sscanf(arg, "%s %s", func, strarg) == 2) {
    write("Calling " + func + "(\"" + strarg + "\") in ");
    write(mname(mark) + " returned:\n");
    write(call_other(mark, func, strarg));
    return 1;
  }
  if(sscanf(arg, "%s %d", func, intarg) == 2) {
    write("Calling " + func + "(" + intarg + ") in");
    write(mname(mark) + " returned:\n");
    write(call_other(mark, func, intarg));
    return 1;
  }
  write("Calling " + arg + "() in\n");
  write(mname(mark) + " returned:\n");
  write(call_other(mark, arg));
  return 1;
}

public int do_mdump(string arg) {
  int i;
  int sizeinv;
  object *inv;

  if(arg) return 0;
  if(!mark) {
    write("No mark found.\n");
    return 1;
  }
  write(mname(mark) + " contains:\n");
  sizeinv = sizeof(inv = all_inventory(mark));
  if(!sizeinv) {
    write("  Nothing.\n");
    return 1;
  }
  print_inv(inv, sizeinv);
  return 1;
}

public int do_mstat(string arg) {
  if(arg) return 0;
  write("Current status of your magic marker:\n");
  write("  Light level: " + lightlev + "\n");
  write(mark ? "  Mark:        " + mname(mark) + "\n" :
	"  No mark set.\n");
  write(altmark ? "  Alt mark   : " + mname(altmark) + "\n" :
	"  No alt mark set.\n");
  return 1;
}

public int do_mlight(string arg) {
  int lev;

  if(!arg) {
    write("The current light level is " + lightlev + ".\n");
    return 1;
  }
  if(sscanf(arg, "%d", lev)) {
    lightlev = lev;
    set_light(lev - set_light(0));
    write("Light level now set to " + lightlev + ".\n");
    return 1;
  }
  write("Set the light to what level?\n");
  return 1;
}

public int do_mfind(string arg) {
  int i;
  object obj;
  object env;
  object *inv;

  if(obj = find_living(arg)) {
    if(env = ENV(obj)) {
      write(mname(obj) + " is in " + FN(env) + ":\n");
      env->long();
      inv = all_inventory(env);
      print_inv(inv, sizeof(inv));
      return 1;
    }
    write(obj->NAME + " has no environment.\n");
    return 1;
  }
  if(obj = find_object(arg)) {
    if(env = ENV(obj)) {
      write(mname(obj) + " is in " + FN(env) + ":\n");
      env->long();
      inv = all_inventory(env);
      print_inv(inv, sizeof(inv));
      return 1;
    }
    write(obj->NAME + " has no environment.\n");
    return 1;
  }
  write("Cannot find " + arg + ".\n");
  return 1;
}

public int do_mdest(string arg) {
  object env;

  if(arg) return 0;
  if(!mark) {
    write("No mark found.\n");
    return 1;
  }
  write("Destructed " + mname(mark) + ".\n");
  if(env = ENV(mark)) write("New mark is " + mname(env) + ".\n");
  else write("No new mark.\n");
  destruct(mark);
  mark = env;
  return 1;
}

public int do_mdestall(string arg) {
  int i;
  int sizeinv;
  object *inv;

  if(arg) return 0;
  if(!mark) {
    write("No mark found.\n");
    return 1;
  }
  sizeinv = sizeof(inv = all_inventory(mark));
  if(!sizeinv) {
    write(mname(mark) + " contains nothing.\n");
    return 1;
  }
  write("Destructing all items in " + mname(mark) + "...\n");
  for(i = 0; i < sizeinv; i++) {
    if(!interactive(inv[i])) {
      write(mname(inv[i]) + " destructed.\n");
      destruct(inv[i]);
    }
  }
  return 1;
}

public int do_mmove(string arg) {
  if(arg) return 0;
  if(!mark) {
    write("No mark found.\n");
    return 1;
  }
  if(!altmark) {
    write("No alt mark found.\n");
    return 1;
  }
  write("Moved " + mname(mark) + " to " + mname(altmark) + ".\n");
  move_object(mark, altmark);
  return 1;
}

public int do_mcode(string arg) {
  if(arg) return 0;
  write("Not implemented as yet.\n");
  return 1;
}

public int do_L(string arg) {
  int i;
  object env;
  object *inv;

  env = ENV(TP);
  if(env) {
    write("Enhanced look for " + mname(env) + ":\n");
    env->long();
    inv = all_inventory(env);
    print_inv(inv, sizeof(inv));
    return 1;
  }
  write("You have no environment.\n");
  return 1;
}

int do_I(string arg) {
  int i;
  int sizeinv;
  object *inv;

  sizeinv = sizeof(inv = all_inventory(TP));
  write("Enhanced inventory. You are carrying:\n");
  if(!sizeinv) {
    write("Nothing.\n");
    return 1;
  }
  print_inv(inv, sizeinv);
  return 1;
}

static int move_mark(object new) {
  if(mark) write("Changed mark from " + mname(mark) + ".\n");
  mark = new;
  write("New mark is " + mname(mark) + ".\n");
  return 1;
}

static int move_altmark(object new) {
  if(altmark) write("Changed alt mark from " + mname(altmark) + ".\n");
  altmark = new;
  write("New alt mark is " + mname(altmark) + ".\n");
  return 1;
}

static string mname(object obj) {
  string sh;

  if(!(sh = obj->short())) sh = "Invisible Object";
  return sh + " (" + FN(obj) + ")";
}

static void print_inv(object *inv, int sizeinv) {
  int i;
  string sh;

  for(i = 0; i < sizeinv; i++) {
    if(!(sh = inv[i]->short())) sh = "Invisible Object";
    printf("  %-3d %-30s (%s)\n", (i + 1), sh, FN(inv[i]));
  }
}

public string query_auto_load() {
  string str;

  sscanf(FN(TO), "%s#%*d", str);
  return str + ":";
}
