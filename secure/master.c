#pragma strict_types

/*
 * MOVE THIS FILE TO /secure/master.c !
 *
 * This is the LPmud master object, used from version 3.0.
 * It is the second object loaded after void.c.
 * Everything written with 'write()' at startup will be printed on
 * stdout.
 * 1.  reset() will be called first.
 * 2. flag() will be called once for every argument to the flag -f
 * 	supplied to 'parse'.
 * 3. epilog() will be called.
 * 4. The game will enter multiuser mode, and enable log in.
 *
 * This version of master.c is specifically designed to be used with mudlib
 * 2.4.6 or earlier. The master.c for mudlib 3.0 will be supplied with
 * that source.
 *
 * One thing is different in the file access permission system in game
 * driver 3.0. The master object can read and write any file.
 * That means that all occurences of such
 * manipulations below must be carefully garded against calls from
 * elsewhere. Always make a comment at the start of a function that is doing
 * such things, to make it easy for other to quickly assert security.
 * The master object can of course not access files above the mudlib
 * directory.
 */

#include "/guild/guild_defs.h"
#include "/sys/include/sys_arches.h"
#include "/sys/include/sys_levels.h"

#define WIZSCAN_OBJECT   "secure/scan_wiz"
#define TI               this_interactive()
#define PO               previous_object()
#define SIMUL_EFUN       "/secure/simul_efun"
#define SPARE_SIMUL_EFUN "/secure/simul_efun2"
#define	CD               "/sys/chatd"
#define AUTO_INC_FILE    "/include/include.h"
#define PLAYER_OB        "/sys/player"

#define	PW_EXPIRY        60	// 60 days
#define	PW_WARN          7	// 1 week

static inherit SIMUL_EFUN;

// global variable to save in /secure/WIZSAVE
// 23-Aug-94: add password expiry routines (for wizards only)

mapping wiz_info = ([ ]);
mapping sanc_info = ([]);    // sanctions: [name:{dir,...}]

int             lock_level;		/* used for locking the game */
int             lock_guild;		/* used for locking guilds */
static mapping  global_command_modifiers = ([ ]);

/* Prototyping */

mixed   creator_file(string object_name);
void    move_or_destruct(object what, object to);
void    wiz_scan();
int     get_wiz_level(string name);
string  *epilog(int i);


/* 930720 HERP: set the lock level */

int set_lock_level(int level) {
  if(TI && TI->query_level() >= L_ARCH) {
    lock_level = level;
    save_object("/secure/WIZSAVE");
    return level;
  }
  else
    return -1;
}

int query_lock_level() {
  return lock_level;
}

/* 931010 HERP: set the lock guild */
/* note that this is a bitarray:
   a guild is locked when the corresponding bit
   in the lock_guild is set to 1
*/

int set_lock_guild(int guild) {
  if(TI && TI->query_level() >= L_ARCH) {
    lock_guild = guild;
    save_object("/secure/WIZSAVE");
    return guild;
  }
  else
    return -1;
}

int query_lock_guild() {
  return lock_guild;
}

// load the wizdata again if we was reloaded
void master_reload() {
  string  emsg, file, str;
  int     sz, i;

  file = AUTO_INC_FILE;
  sz = file_size(file);
  if(sz > 0 && sz < 25000)
    str = read_file(file);
  if(!str)
    str = "#pragma combine_strings";
  str += "\n";
  set_auto_include_string(str);
//  set_auto_include_string("#pragma combine_strings\n"); /* HERP */

  global_command_modifiers=([
        "e":	"east",
        "w":	"west",
        "n":	"north",
        "s":	"south",
        "u":	"up",
        "d":	"down",
        "ne":	"northeast",
        "nw":	"northwest",
        "se":	"southeast",
        "sw":	"southwest",
        "f":   "forward",
        "b":   "backward",
        "l":	"look"
  ]);
  write("Retrieving master data.\n");
  if(file_size("/secure/WIZSAVE.o") < 1 || 
    (emsg = catch(restore_object("/secure/WIZSAVE")))) {
    write("FATAL ERROR in restoring /secure/WIZSAVE! Using defaults.\n");
    printf("Reason: %s\n", emsg);
    wiz_info=([
      "herp": ({ WL_GOD, "master_default", -1, -1, -1, }),
    ]);
    sanc_info=([
      "herp": ({ }),
    ]);
// 071197: Sauron: Added default arch levels.
    for(i = 0; i < sizeof(ARCHES); i++) {
      wiz_info[ARCHES[i]]  = ({ WL_ARCH, "master_default", -1, -1, -1, });
      sanc_info[ARCHES[i]] = ({ });
    }
  }
}

void inaugurate_master(object ob) {
  master_reload();
}

#if 1
/*
 * To test a new function xx in object yy, do
 * parse "-fcall yy xx arg" "-fshutdown"
 */

void flag(string str) {
  string file, arg;
  int num_arg;

  write("flag(" + str + ")\n");

  if(sscanf(str, "for %d", num_arg) == 1) {
    write("Got : " + catch(this_object()->xx(num_arg)) + "\n");
    return;
  }
  if(str == "shutdown") {
    shutdown();
    return;
  }
  if(sscanf(str, "dhrystone %d", arg) == 1) {
    call_other("players/lars/dry", "main", arg);
    return;
  }
  if(sscanf(str, "echo %s", arg) == 1) {
    write(arg + "\n");
    return;
  }
  if(sscanf(str, "apply %s", arg) == 1) {
    arg = (string)call_other(this_object(), arg);
    write("Got " + arg + " back.\n");
    return;
  }
  if(sscanf(str, "call %s %s", file, arg) == 2) {
    arg = (string)call_other(file, arg);
    write("Got " + arg + " back.\n");
    return;
  }
  if(str=="scan_wiz") {
    wiz_scan();
    write("Call to scan_wiz complete.\n");
    return;
  }
  if(str=="lherp") {
    write("catch(players/herp/xa) = " +
           catch("/players/herp/xa"->load()) + "\n");
    shutdown();
    return;
  }
  write("master: Unknown flag " + str + "\n");
}
#endif

void reset(int arg) {		/* Load Rxxx service */
#if 1
  if(arg) return;
#else
  init_imp_hosts();
  if (arg)
    return;
  guild_heads=allocate(NUM_GUILDS);
#endif
}

string *epilog(int load_empty) {
  string *prefiles, buffer, *res, *mi;
  int    i;
  object simf;
  mixed  *mv;

  res=({ });
  if(load_empty) {
    write("Not preloading.\n");
    return ({ });
  } 
  if(file_size("/secure/init_file") > 0
        && (buffer = (string)read_file("/secure/init_file"))) {
    write("Preloading.\n");
    prefiles = explode(buffer,"\n");
    for(i = 0; i < sizeof(prefiles); i++) {
      if(prefiles[i][0] != '#') 
        res+=({ prefiles[i] });
    }
// get a list of all wizzes to load the castles
    prefiles = m_indices(wiz_info);
    for(i = 0; i < sizeof(prefiles); i++) {
      if(wiz_info[prefiles[i]][0] >= L_WIZ) 
        res+=({ "players/" + prefiles[i] + "/castle" });
    }
    res+=({ "room/quest_room" });
  }
  else {
    write("No preload-file or file not accessable! Not preloading.\n");
    return ({ });
  }
  return res;
}

void preload(string file) {
  string  err;
  int     x;

  if((x = strstr(file,".c")) != -1)
    file=file[0..x-1];

  if(file_size(file + ".c") < 0 )
    return;
  
  err=0;
  printf("%s.c\n", file);
  if(err = catch(call_other(file,"??")))
    printf("\tCould not load: %s:\n\t%s\n", file, err);
}

/*
 * This function is called every time a player connects.
 * input_to() can't be called from here.
 */

object connect() {
  string ret;
  object ob;

#if 0
  write("Herp says: Please ask Llort to get a body for you!\n");
  write("Llort says: I'm busy with my guild, go ask James.\n");
  write("James says: Anyone seen Moonchild? A player wants to log on.\n");
  write("Moonchild says: Um. I can't remember the latest player file.\n");
  write("Linkdead says: YOU ARE MINE!\n");
  write("file_name(this_object())+" Connect to login.c...");
  ret = (string)catch(ob = clone_object("secure/login"));
  write("\n");
  if(ret) {
    printf("%s\n", ret);
    return 0;
  }
#else
  ob = clone_object("secure/login");
#endif
  return ob;
}

int xx(int arg) {
  return 1/arg;
}

/*
 * This function is called for a wizard that has dropped a castle.
 * The argument is the file name of the object that called create_wizard().
 * Verify that this object is allowed to do this call.
 */

int verify_create_wizard(object ob) {
  int dummy;

  return sscanf(file_name(ob), "room/port_castle#%d", dummy) == 1;
}

/*
 * Get the owner of a file. This is called from the game driver, so as
 * to be able to know which wizard should have the error.
 */

string get_wiz_name(string file) {
  string name, rest;

// 071197: Sauron: Commented out.
#if 0
  printf("get_wiz_name: %s\n", file);
#endif // 0

  if(sscanf(file, "players/%s/%s", name, rest) == 2)
    return name;
  else
    return 0;
}

/*
 * Write an error message into a log file. The error occured in the object
 * 'file', giving the error message 'message'.
 */

void log_error(string file, string message) {
  string name;

  name = get_wiz_name(file);
  if(!name)
    name = "log";
  name = "/log/"+name;
  write_file(name, message);
  if(this_player() && interactive(this_player())
                   && this_player()->query_immortal())
    write(message);
}

int query_player_level(string what);

void runtime_error(string error, string program, string current_object,
                   int line) {
/* 071197: Sauron: Tidied up the error msg seen by wizards.
  write(current_object ? error + "program: " + program + ", object: " +
        current_object + " line " + line + "\n"
        :       error);
*/
  if(current_object)
    write(
error+"\
program: "+program+"\n\
object : "+current_object+"\n\
line   : "+line+"\n");
  else
    write(error);
}

void xruntime_error(string error, string program, string current_object,
                    int line) {
/* 071197: Sauron: Tidied up the error msg seen by wizards.
    catch(write(query_player_level("error messages") ?
          current_object ? error + "program: " + program + ", object: "
          + current_object + " line " + line + "\n" : error
          : "Your sensitive mind notices a wrongness in the fabric of space.\n"
          ) );
*/
  if(this_player() && query_ip_number(this_player())) {
    if(query_player_level("error messages"))
      catch(runtime_error(error,program,current_object,line));
    else
      catch(write("Your sensitive mind notices a wrongness in the fabric \
of space.\n"));
  }
}

/* save_ed_setup and restore_ed_setup are called by the ed to maintain
   individual options settings. These functions are located in the master
   object so that the local gods can decide what strategy they want to use.
   suggestions:
   A setup file for every wizard.
    advantages:	transparent to the user
		            independent of wizard count
		disadvantage:	extra file access at ed invocation
   An array in the master object, wizards are searched by member_array
		advantage:	easy to implement
		disadvantage:	performance degradation with high wizard counts
   An AVL-tree to access wizards by name
		advantage:	can fit any need
		disadvantage:	hard to implement, will need more overhead on
                  small and medium muds than it can ever make
                  good by lg(wizcount) complexity
   Dedicated flags in every wizard object, inherited from /obj/living
		advantages:	easy to implement ( as shown here)
                independent of wizard count
                Will also work for nonm-wizards.
		disadvantage:	care has to be taken to avoid collision with
                  other uses of the /obj/living flags.
*/

/*
 * The wizard object 'who' wants to save his ed setup. It is saved in the
 * file /players/wiz_name/.edrc . A test should be added to make sure it is
 * a call from a wizard.
 *
 * Don't care to prevent unauthorized access of this file. Only make sure
 * that a number is given as argument.
 */

int save_ed_setup(object who, int code) {
  string file;

  if (!intp(code))
    return 0;
  file = "/players/" + lower_case((string)who->query_real_name()) + "/.edrc";
  rm(file);
  return write_file(file, code + "");
}

/*
 * Retrieve the ed setup. No meaning to defend this file read from
 * unauthorized access.
 */

int retrieve_ed_setup(object who) {
  string file;
  int    code;

  file = "/players/" + lower_case((string)who->query_real_name()) + "/.edrc";
  if (file_size(file) <= 0)
    return 0;
  sscanf(read_file(file), "%d", code);
  return code;
}

/*
 * Create a home dritectory and a castle for a new wizard. It is called
 * automatically from create_wizard(). We don't use the 'domain' info.
 * The create_wizard() efun is not really needed any longer, as a call
 * could be done to this function directly.
 *
 * This function can create directories and files in /players. It is
 * garded from calls from the wrong places.
 */

string master_create_wizard(string owner, string domain, object caller) {
  string def_castle, def_workroom;
  string dest, castle, workroom, wizard;
  object player;

  player = find_player(owner);

  if (!player)
    return 0;
  if (!verify_create_wizard(caller)) {
    tell_object(player, "That is an illegal attempt!\n",0);
    return 0;
  }
  if (caller != previous_object()) {
    tell_object(player, "Faked call!\n",0);
    return 0;
  }
  wizard   = "/players/" + owner;
  castle   = "/players/" + owner + "/castle.c";
  workroom = "/players/" + owner + "/workroom.c";

  if (file_size(wizard) == -1) {
    tell_object(player, "You now have a home drirectory: " +
                        wizard + "\n",0);
    mkdir(wizard);
  }
  /* 920414 Herp: set dest to players workroom always
  dest = file_name(environment(player));
  */
  dest = "/players/" + owner + "/workroom.c";

  /* 920414 Herp: create the workroom first */

  def_workroom = "#define NAME \"" + owner + "\"\n\n" +
    read_file("/room/def_workroom.c");
  if (file_size(workroom) > 0) {
    tell_object(player, "You already have a workroom!\n",0);
  }
  else {
    /* The master object can do this ! */
    if (write_file(workroom, def_workroom))
      tell_object(player, "You now have a workroom: "+workroom+"\n",0);
    else
      tell_object(player, "Failed to create your workroom!\n",0);
  }

  def_castle = "#define NAME \"" + owner + "\"\n#define DEST \"" +
    dest + "\"\n" + read_file("/room/def_castle.c");
  if (file_size(castle) > 0) {
    tell_object(player, "You already had a castle!\n",0);
  }
  else {
    /* The master object can do this ! */
    if (write_file(castle, def_castle)) {
      tell_object(player, "You now have a castle: " + castle + "\n",0);
      if (!write_file("/room/init_file", extract(castle, 1) + "\n"))
        tell_object(player, "It couldn't be loaded automatically!\n",0);
    }
    else {
      tell_object(player, "Failed to make castle for you!\n",0);
    }
  }
  /* Add the new wizard to the new-wiz list. Llort 920913 */
  "secure/new_wiz"->add_newwiz(owner);

  return castle;
}

/*
 * When an object is destructed, this function is called with every
 * item in that room. We get the chance to save players !
 */

void destruct_environment_of(object ob) {
  if (!interactive(ob))
    return;
  tell_object(ob, "Everything you see is disolved. Luckily, " +
                  "you are transported somewhere...\n",0);
  ob->move_player("is transfered#/room/void");
}

/*
 * Define where the '#include' statement is supposed to search for files.
 * "." will automatically be searched first, followed in order as given
 * below. The path should contain a '%s', which will be replaced by the file
 * searched for.
 */

string *define_include_dirs() {
//  return ({"/room/%s", "/sys/%s", "/obj/%s" });
// Mangla: As per Sauron's request.
  return ({"/include/%s", "/sys/include/%s",
           "/room/%s", "/sys/%s", "/obj/%s"});
}

/*
 * The master object is asked if it is ok to shadow object ob. Use
 * previous_object() to find out who is asking.
 *
 * In this example, we allow shadowing as long as the victim object
 * hasn't denied it with a query_prevent_shadow() returning 1.
 */

int query_allow_shadow(object ob) {
  return !ob->query_prevent_shadow(previous_object());
}

/*
 * Default language functions used by parse_command() in non -o mode
 */

string *parse_command_id_list() {
  return ({ "one", "thing" });
}

string *parse_command_plural_id_list() {
  return ({ "ones", "things", "them" });
}

string *parse_command_adjectiv_id_list() {
  return ({ "iffish" });
}

string *parse_command_prepos_list() {
  return ({ "in", "on", "under", "behind", "beside" });
}

string parse_command_all_word() {
  return "all";
}

/*
 * Give a file name for edit preferences to be saved in.
 */

string get_ed_buffer_save_file_name(string file) {
  string *file_ar;

  file_ar = explode(file,"/");
  file = file_ar[sizeof(file_ar) - 1];
  return "/players/" + this_player()->query_real_name() +
         "/.dead_ed_files/" + file;
}

/*
 * Give a path to a simul_efun file. Observe that it is a string returned,
 * not an object. But the object has to be loaded here. Return 0 if this
 * feature isn't wanted.
 * 071197: Sauron: Added a backup spare simul_efun object for security in
 *                 case the primary copy doesn't load.
 */

string get_simul_efun() {
  string fname,fname2;
  string s;

  fname  = SIMUL_EFUN;
  fname2 = SPARE_SIMUL_EFUN;

  if((s = catch(call_other(fname, "init_simul")))) {
    printf("Failed to load %s, reason: %s\n",
           fname, s);
    if((s = catch(call_other(fname2, "init_simul")))) {
      printf("Failed to load %s, reason: %s\n",
             fname2, s);
      shutdown();
      return 0;
    }
    else {
      printf("Using spare simul_efun object: %s\n", fname2);
      return fname2;
    }
  }
  else
    return fname;
}

int query_prevent_shadow() {
  return 1;
}

/*
 * There are several occasions when the game driver wants to check if
 * a player has permission to specific things.
 *
 * These types are implemented so far:
 * "trace":		If the player is allowed to use tracing.
 * "wizard":		Is the player considered at least a "minimal" wizard ?
 * "error messages":	Is the player allowed to get run time error messages ?
 */

int query_player_level(string what) {
  if (this_player() == 0)
    return 0;
  switch(what) {
    case "wizard":
      return (int)this_player()->query_immortal();
    case "error messages":
      return (int)this_player()->query_immortal();
    case "trace":
      return (int)this_player()->query_wizard();
  }
}

/* 921031 Herp: Ask if obj1 is allowed to command() obj2 */

int query_allow_command(object obj1,object obj2) {
  int l1, l2;

#if 0
  write("secure/master: query_allow_command ");
  if(obj1) write(file_name(obj1));
  else write("0");
  write(" ");
  if(obj2) write(file_name(obj2));
  else write("0");
  write("\n");
#endif
// Yes, you may force yourself to do things...
  if(obj1 == obj2) return 1;
  if(!obj1 || !obj2) return 0;

  l1 = get_wiz_level((string)obj1->query_real_name());
  l2 = get_wiz_level((string)obj2->query_real_name());

  /* exeption for following! we need to get commands form our leader! */
  if((object)obj2->query_follow_whom() == obj1)
    return 1;

// A monster is never allowed to force a wiz, no matter what monster-level
  if(!interactive(obj1) && l2 || l1 < l2) {
// Sauron: Shouldn't this use log_file()?
    if(!interactive(obj1))
        log_error("COMMAND", file_name(obj1) + " "); 
    log_error("COMMAND",obj1->query_name() + " (" + obj1->query_real_name() +
              "), creator: " + creator(obj1) + " failed to command() " +
              obj2->query_real_name() + " at " + ctime() + "\n");
    return 0;
  }
  return 1;
}

string *get_dir(string path) {
  return efun::get_dir(path);
}

/* this function is needed to reconnect a player */

int valid_exec(string name,object ob,object obfrom) {

#if 0
  printf("name   %s\n",name);
  printf("ob     %s\n", ob ? file_name(ob) : "N/A");
  printf("obfrom %s\n", obfrom ? file_name(obfrom) : "N/A");
#endif
  if(name[0..3] == "sys/" || name == "secure/login.c"
                          || name[0..29] == "players/llort/guild/familiars/") {
    CD->remove_chat_ob(obfrom);
    ob->add_chat();
    return 1;
  }
  return 0;
}

mixed creator(string object_name) {
  return creator_file(object_name);
}

mixed creator_file(string object_name) {
  string *path;

  path = explode(object_name,"/") - ({"","."});
  switch(sizeof(path) && path[0]) {
  case "open":
  case "ftp":
  case "log":
    return 0;
  case "players":
    if(sizeof(path) < 3)
      return 0;
    return path[1];
/*
  case "domains":
    if(sizeof(path) < 3)
      return 0;
    return capitalize(path[1]);
 */
  default:
    return 1;
  }
}

mixed valid_write(mixed  path,     string eff_user,
                  string call_fun, object caller) {
  string user,file;

#if 0
  /*HERP*/
  write(file_name(this_object()) + "::valid_write " + call_fun +
        "(" + path + ") by " + file_name(caller) + "\n");
#endif
  switch(call_fun) {
    case "save_object":
      path = explode(path,"/") - ({"","."});
      if(member_array("..",path) >= 0)
        return 0;
      file = file_name(previous_object());
      if(stringp(user = creator_file(file)) ) {
        if(user[0] >= 'A' && user[0] <= 'Z') {
          if(sizeof(path) >= 3 && path[0] == "domains"
                && path[1] == lower_case(user))
            return implode(path,"/");
        }
        else {
          if(sizeof(path) >= 3 && path[0] == "players"
                               && path[1] == user)
            return implode(path,"/");
        }
      }
      else {
        if(file[0..3] == "obj/" || file[0..4] == "room/"
                                || file[0..6] == "secure/"
                                || file[0..3] == "sys/"
                                || file[0..7] == "masters/"
                                || file[0..6] == "boards/"
                                || file[0..4] == "news/"
                                || file == "spells/master"
                                || file == "abilities/master"
                                || file[0..3] == "std/")
          return implode(path,"/");
      }
    case "copy_file":
    case "write_file":  /* the master can write a file */
      if((path[0..4] == "/log/" && member_array('/',path[5..]) < 0
            && path[5] != '.' && strlen(path) <= 35) ) {
        return path;
      }
      if(caller == this_object()) return 1;
      break;
    case "ed_start":
      path = "/"+path;
      break;
    case "mkdir":
    case "rmdir":
    case "write_bytes":
    case "remove_file":
      if(caller == this_object())
        return 1;
    case "cindent":
      break;
    case "do_rename":
      if(file_name(caller)==SIMUL_EFUN[1..<1] )
        return path;
      break;
    default:
      return 0; // deny access
  }
  set_this_object(caller);
  if(this_player() && query_ip_number(this_player()) ) {
    path = (string)this_player()->valid_write(path);
    if(!stringp(path)) {
      if(path)
        write("Bad file name (from valid_write).\n");
      return 0;
    }
    else
      return path;
  }
  else {
    path = (string)PLAYER_OB->valid_write(path);
    if(stringp(path))
      return path;
  /* else return 0, denying access */
  }
}

mixed valid_read(string path,     string eff_user,
                 string call_fun, object caller) {
  string user;
#if 0
  /*HERP*/
  write(file_name(this_object()) + "::valid_read " + call_fun +
        "(" + path + ") by " + file_name(caller)+"\n");
#endif
  switch(call_fun) {
  case "file_size":
    return SIMUL_EFUN->clean_path(path);
  case "restore_object":
    return 1;
  case "ed_start":
// 071197: Sauron: Rewritten to allow call from bin cmd to work.
    if(previous_object() && previous_object() != this_player() &&
       file_name(previous_object())[0..3] != "sys/")
      return 0;
    if(!path) {
// request for file with last error
      mixed *error;
      error = get_error_file(({string})this_player()->query_real_name());
      if(!error || error[3]) {
        write("No error.\n");
        return 0;
      }
      printf("File '%s' line %d.\nError: %s\n",
             error[0],error[1],error[2]);
      return error[0];
    }
    else if(path[0..0] != "/")
      path = "/"+path;
    if(this_player() && !(this_player()->valid_read(path, 1)))
      return 0;
  case "read_file":
  case "copy_file":
//  case "file_size":
  case "read_bytes":
  case "get_dir":
    if(caller == this_object()
          || file_name(caller) == "secure/scan_wiz"
          || file_name(caller)[0..3] == "sys/"
          || file_name(caller)[0..6] == "secure/")
      return 1;
  case "tail":
  case "print_file":
  case "make_path_absolute": // internal use, see below
  case "do_rename":
    set_this_object(caller);
    if(this_player() && query_ip_number(this_player())) {
      path = (string)this_player()->valid_read(path);
      if(!stringp(path)) {
        if(path)
          write("Bad file name (from valid_read).\n");
        return 0;
      }
      else
        return path;
    }
    path = (string)PLAYER_OB->valid_read(path);
    if(stringp(path)) {
      return path;
    }
    return 0;
  default:
    return 0;
  }
  /* if a case failed to return a value or the caller function wasn't
   * recognized, we come here.
   * The default returned zero indicates deny of access.
   */
  return 0;
}

/*#ifdef COMPAT_FLAG*/
mixed *prepare_destruct1(object ob) {
  object super;
  object me;

  super = environment(ob);
  me = this_object();
  set_this_object(previous_object());
  catch(ob->notify_destruct(ob));
  if (super) {
    mixed error, *errors;
    mixed weight;

    errors = ({});
    catch(super->notify_leave(ob,0));
    if(living(ob) ) {
      if(error = catch(super->exit(ob),0))
        errors = ({"exit: "+error});
    }
    if(error = catch((weight = ({mixed})ob->query_weight()),0) ) {
      set_this_object(me);
      return ({"query_weight: "+error}) + errors;
    }
    if(weight && intp(weight)) {
      if(error = catch(super->add_weight(-weight),0)) {
        set_this_object(me);
        return ({"add_weight: "+error}) + errors;
      }
    }
  }
  set_this_object(me);
  return ({});
}
/*#endif /* COMPAT_FLAG */

mixed prepare_destruct(object ob) {
  
  string fname;
  object super;
  mixed *errors;
  int i;

  /* (Pat) this does not work. Dunno why, but objects cannot be dested anymore.
   * or at least, the memory won't be freed *shrug*
   * if(!clonep(ob) && file_name(ob)[0..3]=="sys/" && 
   * this_player() && !this_player()->valid_write("/"+file_name(ob)))
   * return 1;
   */
// when a player tries to destruct another player
  
  if(interactive(ob) && this_player()!=ob) {
    SIMUL_EFUN->tell_object(ob, "\n** You were destructed by " +
                            this_player()->query_real_name() + " **\n");
    SIMUL_EFUN->log_file("ape", this_player()->query_real_name() +
                         " destructed " + ob->query_real_name() + " at " +
                         ctime() + "\n\t\t HOST: " +
                         query_ip_number(this_player()) + " " + "FILE: " +
                         file_name(this_player()) + "**\n");
  }

// 161093 HERP: remove the entry from sys/chatd the 2nd call is in valid_exec
  if(query_once_interactive(ob)) 
    CD->remove_chat_ob(ob);


  /*#ifdef COMPAT_FLAG*/
#if 1
  errors = prepare_destruct1(ob);
  for(i = sizeof(errors) -1; i >= 0; i-- )
    printf("%s\n", errors[i]);
#endif /* COMPAT_FLAG */
  super = environment(ob);
  if(!super) {
    object item;

    while ( item = first_inventory(ob) ) {
      destruct_environment_of(item);
      if(item && environment(item) == ob) destruct(item);
    }
  }
  else {
    while(first_inventory(ob))
      move_or_destruct(first_inventory(ob), super);
  }
  return 0; // success
}


void move_or_destruct(object what, object to) {
/* An error in this function can be very nasty. Note that unlimited recursion
 * is likely to cause errors when environments are deeply nested
 */
#if 0
  log_file("DESTRUCT", "move_or_destruct(" + file_name(what) + "," +
           to?file_name(to):"0"+"\n");
#endif
#ifdef COMPAT_FLAG
  do {
    int res;
    if(catch( res = transfer(what, to) ))
      res = 5;
    if(!(res && what))
      return;
  }
  while((res == 1 || res == 4 || res == 5) && (to = environment(to)));
#else /* !COMPAT_FLAG */
  if ( !catch( what->move(to, 1) ) ) return;
#endif /*COMPAT_FLAG */
  
  // Failed to move the object. Then, it is destroyed.
  destruct(what);
}

/* privilege_violation is called when objects try to do illegal things,
 * or files being compiled request a privileged efun.
 *
 * return values: 
 *   1: The caller/file is allowed to use the privilege.
 *   0: The caller was probably misleaded; try to fix the error.
 *  -1: A real privilege violation. Handle it as error.
 */

int privilege_violation(string what, mixed who, mixed where) {
  string tmp;

#if 1
  switch(what) {
    case "nomask simul_efun":
      if(objectp(who))
        tmp=file_name(who);
      else
        tmp=""+who;
      if(tmp[0..3]=="sys/" || tmp[0..6]=="secure/")
        return 1;
#if 0
      if (who == SIMUL_EFUN) {
        return 1;
      }
#endif // 0
      return -1;
      break;

    case "call_out_info":
      return 1; /* allow anyone to use call_out_info - James */
      break;

    case "pwent":
// it's okay for the /secure/ mudlib
      if (file_name(who)[0..6]=="secure/")
        return 1;
      else
        return -1;

    default:
      return -1; // Make this violation an error
  }
#endif
}

/* this routine is called from the game-driver from new_set_snoop */
/* if snooping is to be turned off, we enter with snopee = 0 */

int valid_snoop(object snooper, object snoopee) {
  object snooped_by;

  if(!snoopee) {
    return 1;	/* turn off snooping = always success */
  }

  /* non-interactives never can snoop or be snooped */

  if(!snooper || !interactive(snooper)
              || !interactive(snoopee))
    return 0;

  /* if the victim is snooped already, allow snooping
   * only if snooped-by's level is < that our level
   */

  if(snooped_by=efun::query_snoop(snoopee)) 
    if(snooped_by->query_level() >= snooper->query_level())
      return 0;

  if(snoopee==this_interactive())
    return 1; // snoop ourself ? okay...

//  if(snooper->query_real_name() == "exos") {
//    SIMUL_EFUN->log_file("RANDOM", "Attempt on " + snoopee->query_real_name() +
//               " at " + ctime() + "\n");
//    }
  return snooper->query_level() > snoopee->query_level();
}

int valid_query_snoop(object wiz) {
  return 1;
}

static void _list_wiz(string idx,mixed *data) {
  int ft;

  printf("%-15s %6d %-15s %s %3d %3d %3d\n",
    idx,
    data[0],
    data[1],
    (ft=ftime("/p/" + to_string(({idx[0]})) + "/" + idx + ".o")) ?
    ctime(ft) : "      *missing*",
    data[2],
    data[3],
    data[4]);
}

void list_wiz() {
  if (this_player()->query_level()<L_ARCH) return;
  printf("%-15s %6s %-15s %s\n%s\n",
	   "WIZNAME","level","inaugurated by","Last Accessed",
     "===============================================================");
  walk_mapping(wiz_info,"_list_wiz");
  printf("Nr. of wizards: %d\n",sizeof(wiz_info));
}

static void _print_wiz(string idx, mixed *data) {
  write_file("ALL_WIZ","pwfetch "+idx+"\n");
}

void print_wiz() {
  if(this_player()->query_level()<L_ARCH) return;
  walk_mapping(wiz_info,"_print_wiz");
}

void _cwp(string idx,mixed *data) {
  if(getpwent(idx)==0)
    setpwent(idx,"none");
}

void cwp() {
  if(this_player()->query_level()<L_ARCH) return;
  walk_mapping(wiz_info,"_cwp");
}

static void wiz_scan() {
  wiz_info=(mapping)WIZSCAN_OBJECT->create_list("");
  save_object("/secure/WIZSCAN");
}

int get_wiz_level(string name) {
  mixed *tmp;

#if 0
  printf(file_name(this_object()) + "::get_wiz_level(\"%s\")\n", name);
#endif
  if(!name || !(tmp=wiz_info[name]))
    return 0;
  else
    return tmp[0];
}

/*
 * get_pwlim
 *
 *	returns how many days the password may remain unchanged
 *
 */
int get_pwlim(string name) {
  mixed *tmp;

  if (!name || !(tmp=wiz_info[name]))
    return -1;
  else
    return tmp[2];
}

/*
 * get_pwwarn
 *
 *	returns the count of days to warn a wizard before the password
 *		expires
 *
 */
int get_pwwarn(string name) {
  mixed *tmp;

  if(!name || !(tmp=wiz_info[name]))
    return -1;
  else
    return tmp[3];
}

/*
 * get_pwstamp
 *
 *	returns the time stamp when the password last changed
 *		(in seconds since 1970)
 */
int get_pwstamp(string name) {
  mixed *tmp;

  if(!name || !(tmp=wiz_info[name]))
    return -1;
  else
    return tmp[4];
}

/* set_pwstamp
 *
 *	touch the password time stamp field
 */

int set_pwstamp(string name,int s) {
  mixed *tmp;

  if (file_name(previous_object())[0..6]!="secure/") return -1;
  if (!name || !(tmp=wiz_info[name])) return -1;
  tmp[4]=s;
  save_object("/secure/WIZSAVE");
}

// change a wizards level: level<L_APPR means remove him

int set_wiz_level(string name,int level) {
  string prom;

  if(!name || !level || !stringp(name) || !intp(level))
    return 0;
  if(!get_wiz_level(name) && level<L_APPR)
    return 1;
  if(TI && (string)TI->query_real_name()==name
        && (int)TI->query_level()==L_PLAYER
        && (int)level==L_APPR) {
    wiz_info[name]=({level,"advance",PW_EXPIRY,PW_WARN,0});
    save_object("/secure/WIZSAVE");
    return 1;
  }
#if 0
  write("Master: ");
  if(TI) printf("TI = %O, ",TI);
  else write("TI = NO TI!");
  if(PO) printf("PO = %O, ",PO);
  else write("PO = NO PO!");
  printf("level = %d\n",level);
#endif

  if(TI && TI->query_login_object()) {
    SIMUL_EFUN->log_file("PROMOTE","Login changed " + name +
                         "'s level to " + level + " at " +
                         ctime() + ".\n");
    if(level<L_APPR)
      wiz_info=m_delete(wiz_info,name);
    else
      wiz_info[name]=({level,prom,PW_EXPIRY,PW_WARN,0});
    save_object("/secure/WIZSAVE");
    return 1;
  }
  if(!TI || !(prom=(string)TI->query_real_name())
#if 0
         || get_wiz_level(prom)<L_ARCH
         || level>=get_wiz_level(prom)
         || get_wiz_level(prom)<=get_wiz_level(name))
#else
         || get_wiz_level(prom)<L_ARCH
         || (level >= get_wiz_level(prom) &&
            prom!="tatsuo" &&
            prom!="redsexy" &&
            prom!="wilbie")
         || (get_wiz_level(prom)<=get_wiz_level(name) &&
            prom!="tatsuo" &&
            prom!="redsexy" &&
            prom!="wilbie")) 
#endif
    return 0;
  SIMUL_EFUN->log_file("PROMOTE", prom + " changed " + name +
                       "'s level to " + level + " at " +
                       ctime(time()) + ".\n");
  if(level<L_APPR)
    wiz_info=m_delete(wiz_info,name);
  else
    wiz_info[name]=({level,prom,PW_EXPIRY,PW_WARN,0});
  save_object("/secure/WIZSAVE");
  return 1;
}

/* This is a simple standard command modifier */

string modify_command_global(string str) {
  return global_command_modifiers[str]; 
}

// ----- patience / sanctions ----------------------------------------------

nomask int set_sanction(string giver,string rec) {
  if (!rec || !giver)
    return 0;

  if(!this_player() || !interactive(this_player())
                    || !query_ip_number(this_player())
                    || !(this_player()->query_archwiz())
                    || !get_wiz_level(rec)
                    || !get_wiz_level(giver))
    return 0;
  if(!sanc_info[giver] || !sizeof(sanc_info[giver]))
    sanc_info[giver] = ({rec});
  else {
    if(member_array(rec, sanc_info[giver]) >= 0)
      return 0;
    else
      sanc_info[giver] = sanc_info[giver] + ({rec});
  }
  save_object("/secure/WIZSAVE");
  return 1;
}

nomask int rem_sanction(string giver, string rem) {
   if(!giver || !rem)
     return 0;

   if(!this_player() || !interactive(this_player())
                     || !query_ip_number(this_player()))
     return 0;

   if(!(this_player()->query_archwiz())
         && (string)this_player()->query_real_name() != giver)
     return 0;

   if(!sanc_info[giver] || !sizeof(sanc_info[giver])) 
     return 0;
   else {
     if(member_array(rem,sanc_info[giver]) < 0)
       return 0;
     else {
       sanc_info[giver] = sanc_info[giver] - ({rem});
       if(!sizeof(sanc_info[giver]))
         sanc_info = m_delete( sanc_info, giver );
     }
   }
   save_object( "/secure/WIZSAVE" );
   return 1;
}

nomask int valid_access(string who, string where) {
   if(!sanc_info[where] || !sizeof(sanc_info[where]))
      return 0;
   if(member_array(who, sanc_info[where]) < 0)
      return 0;
   else
      return 1;
}

nomask string get_sanctions(string who) {
  string res;
  int    len;
  mixed  *idx;

  if(!who)
    return "error on arguments!\n";

  res = "Sanction-information about: " + who + "\n";

  res += "Who can write to my dir: ";
  len = sizeof(sanc_info[who]);
  for(--len; len >= 0; len--)
    res += sanc_info[who][len] + ", ";

  idx = m_indices( sanc_info );
  res += "\nAt whoms dir can I write: ";
  len = sizeof(idx);
  for(--len; len >= 0; len-- ) {
    if(member_array( who, sanc_info[idx[len]] ) > -1 )
      res += idx[len]+", ";
  }
  return res + "\n";
}

nomask void dump_sanctions() {
  int    len, i;
  mixed  *idx;
  string res;

  if(!this_player() || !(this_player()->query_archwiz()))
    return;

  len = m_sizeof( sanc_info );
  if(!len) {
    write("No sanctions exist at the moment !\n"); 
    return;
  }
  idx = m_indices(sanc_info);
  res = "Wizard\tsanctions\n";

  for(--len; len >= 0; len--) {
    res += idx[len] + "\t";
    i = sizeof(sanc_info[idx[len]]);
    if(i == 0) res += "none\n";
    else {
      for(--i; i >= 0; i--)
        res += sanc_info[idx[len]][i] + ", ";
      res += "\n";
    }
  }

  this_player()->more_string(res);
}

// Mangla: NOTHING below this point is in the game and I do not
//         see any plans to put it in the game. I left it here
//         just in case though.
#if 0 // old code for imp_host and such.
mixed *guild_heads;
static mapping imp_hosts = ([ ]);
void    send_ping_q_to_all();

void init_imp_hosts() {
  imp_hosts=([
    /* Name		   ip#		   UDP   VR MLIB HS PR  TIME */
    "PaderMud"     : ({ "131.234.2.42",   2500, "", "", "", -1, "" }),
    "Kingdoms"     : ({ "129.16.117.17",  2500, "", "", "", -1, "" }),
    "WonderLand"   : ({ "192.124.156.11", 2500, "", "", "", -1, "" }),
    "Nightfall"    : ({ "134.2.62.161",   6889, "", "", "", -1, "" }),
    "HmiMud"       : ({ "134.30.15.99",   2500, "", "", "", -1, "" }),
    "Tubmud"       : ({ "130.149.19.20",  4246, "", "", "", -1, "" }),
    "Muddy_Waters" : ({ "131.215.9.49",   2500, "", "", "", -1, "" }),
    "Angalon"      : ({ "131.204.10.91",  2500, "", "", "", -1, "" }),
    "England-Mud"  : ({ "130.253.192.68", 2500, "", "", "", -1, "" }),
    "MathMud"      : ({ "130.133.4.4",    2500, "", "", "", -1, "" }),
    "Etheria"      : ({ "129.11.144.189", 2500, "", "", "", -1, "" }),
    "WildSau"      : ({ "140.78.40.25",   4246, "", "", "", -1, "" })
    ]);
}

#if 0
/* ----------- */
/* udp recieve */
/* ----------- */
object herp;
#if 0
void receive_imp(string ip,string buf){
string cmd,prm,*parts,key,val;
string *keys,*vals;
mapping parms;
int i;
#if 1
    herp=find_player("herp");
    if (herp) tell_object(herp,buf+"\n",0);
#endif
    if (sscanf(buf,"@@@%s||%s@@@",cmd,prm) !=2)
	if (sscanf(buf,"@@@%s@@@",cmd) !=1) return;	/* empty */
	else prm=0;

    keys=vals=({});
    if (strlen(prm)) {
	parts=explode(prm,"||");
	for (i=0;i<sizeof(parts);i++)
	    if (sscanf(parts[i],"%s:%s",key,val)==2) {
		keys+=({ key });
		vals+=({ val });
	    }
    }
    parms=mkmapping(keys,vals);
    parms["HOSTADRESS"]=ip;
    call_other(this_object(),cmd,parms);
}
#endif

/* -------------------------------------------------------- *
 *
 * FILE: /sys/udp_mgr.c
 *
 * -------------------------------------------------------- */
#include "/sys/udp.h"
#define	 HM	"HolyMission"
#define  TPQRN	this_player()->query_real_name()
#define  HOST_P	\
    if (!(host=imp_hosts[mud])) {\
	imp_hosts+=([ mud : ({ ip, port }) ]);\
	host=allocate(2);\
	host[0]=ip;\
	host[1]=port;\
    }

int level_compare(object ob1,object ob2) {
  return (ob1->query_level()<=ob2->query_level());
}

string rwho() {		/* Remote wholist format */
object *u;
string msg;
int i,nw,np,nt;

#if 1
    if (!(u=users()))
#else
    call_other(SIMUL_EFUN,"users",u);
    if (!u)
#endif
	msg="Empty mud.\n";
    else {
	u=sort_array(u,"level_compare",this_object());
	nt=sizeof(u);
	msg="";
	herp=find_player("herp");
	for (i=0;i<nt;i++) {
	    msg+=file_name(u[i]);
	    msg+="\n";
	}
	if (herp) tell_object(herp,msg,0);
	nw=np=0;
	for (i=0;i<sizeof(u);i++)
  	    if (u[i]->query_level()>L_PLAYER) nw++;
  	    else np++;
	if (nw==0) msg="No";
	else msg=(string)nw;
	if (nw==1) msg+=" wizard";
	else msg+=" wizards";
	msg+=" and ";
	if (np==0) msg+="no";
	else msg+=(string)np;
	if (np==1) msg+=" player.\n";
	else msg+=" players.\n";
	if (nw>0) {
	    if (nw==1) {
		msg+="Wizard is: ";
		msg+=capitalize((string)u[0]->query_real_name());
	    }
	    else {
		msg+="Wizards are: ";
		for (i=0;i<nw-1;i++) {
		    msg+=capitalize((string)u[i]->query_real_name());
		    msg+=", ";
		}
		msg+="and ";
		msg+=capitalize((string)u[nw-1]->query_real_name());
	    }
	    msg+=".\n";
	}
	if (np>0) {
	    if (np==1) {
		msg+="Player is: ";
		msg+=capitalize((string)u[nt-1]);
	    }
	    else {
		msg+="Players are: ";
		for (i=nw;i<nt-1;i++) {
		    msg+=capitalize((string)u[i]->query_real_name());
		    msg+=", ";
		}
		msg+="and ";
		msg+=capitalize((string)u[nt-1]->query_real_name());
	    }
	    msg+=".\n";
	}
    }
    return(msg);
}

/* -------------------------------------------------------- */

void send_rwho_a(string ip,int port,string mud,string askwiz) {
mixed *host;
string msg;

    if (mud==HM) return;		/* Ourselves ! */
    HOST_P
    msg="@@@"+UDP_RWHO_A+
    "||NAME:"+HM+
    "||PORTUDP:"+query_imp_port()+
    "||RWHO:"+rwho()+
    "||ASKWIZ:"+askwiz+"@@@";
    send_imp(host[0],host[1],msg);
}

void send_ping_q(string ip,int port) {
string msg;
    msg="@@@"+UDP_PING_Q+
    "||NAME:"+HM+
    "||PORTUDP:"+query_imp_port()+"@@@";
    send_imp(ip,port,msg);
}

void send_ping_a(string ip,int port,string mud) {
mixed *host;
string msg;

    if (mud==HM) return;		/* Ourselves ! */
    HOST_P
    msg="@@@"+UDP_PING_A+
    "||NAME:"+HM+
    "||HOST:"+query_net_name()+
    "||VERSION:"+simul_efun_object()->version()+
    "||MUDLIB:2.4.5-based"+
    "||TIME:"+ctime(time())+
    "||PORT:"+query_mud_port()+
    "||PORTUDP:"+query_imp_port()+"@@@";
    send_imp(host[0],host[1],msg);

}

/* +--------------------------------+
   | CAUTION!			    |
   | This routine HAS TO BE STATIC  |
   | We don't want people to send   |
   | fake messages across the net.  |
   +--------------------------------+
*/

static int send_gtell(string mud,string wizfrom,string wizto,string smsg) {
mixed *host;
string msg;

    if (!(host=imp_hosts[mud])) return -1;
    msg="@@@"+UDP_GTELL+
    "||NAME:"+HM+
    "||PORTUDP:"+query_imp_port()+
    "||WIZFROM:"+wizfrom+
    "||WIZTO:"+wizto+
    "||MSG:"+smsg+"@@@"; 
    send_imp(host[0],host[1],msg);
}

static int send_gfinger_q(string mud,string askwiz,string player) {
mixed *host;
string msg;

    if (!(host=imp_hosts[mud])) return -1;
    msg="@@@"+UDP_GFINGER_Q+
    "||NAME:"+HM+
    "||PORTUDP:"+query_imp_port()+
    "||ASKWIZ:"+askwiz+
    "||PLAYER:"+player+"@@@";
    send_imp(host[0],host[1],msg);
}

int send_gtell_w(string mud,string wizto,string msg) {
string wizfrom;
    wizfrom=(string)TPQRN;
    return send_gtell(mud,capitalize(wizfrom),capitalize(wizto),msg);
}

int send_gfinger_w(string mud,string rwiz) {
string wizfrom;
    wizfrom=(string)TPQRN;
    return send_gfinger_q(mud,capitalize(wizfrom),capitalize(rwiz));
}

void send_rwho_q(string mud) {
mixed *host;
string msg;

    if (host=imp_hosts[mud]) {
	msg="@@@"+UDP_RWHO_Q+
	"||NAME:"+HM+
	"||PORTUDP:"+query_imp_port()+
	"||ASKWIZ:"+TPQRN+"@@@";
	send_imp(host[0],host[1],msg);
  }
}

void send_ping_q_to_all() {
int i;
mixed *mi;
mixed *mv;

    mi=m_indices(imp_hosts);
    mv=m_values(imp_hosts);
    for (i=0;i<sizeof(mi);i++) send_ping_q(mv[i][0],mv[i][1]);
}

/* other programs (appr.c) might want to know about it */

mapping query_imp_hosts() { return imp_hosts; }

int valid_remote_wiz(string str) {
  return (file_size("/banish/"+lower_case(str)+".o")==-1
	|| explode(str,"@")[0]=="GTELL");
}
#define GDR_INV(x)	send_gtell(p["NAME"],"Gamedriver",x,\
			"You are not allowed to use "+HM+".")

#define GDR_NLW(x)	send_gtell(p["NAME"],"Gamedriver",x,\
			"No such local wizard.")

#define GDR_BSY(x)	send_gtell(p["NAME"],"Gamedriver",x,\
			"That wizard is busy right now, try again later.")

/* ------------------------------------------------------------------- */
/* Process incoming protocol. This will either send a response to the  */
/* mud who asked for some information, or inform a local wiz about     */
/* what just has been sent.					       */
/* Please NOTE: none of this functions has to be player/wiz accessible */
/* ------------------------------------------------------------------- */

void rwho_q(mapping p) {
string wiz_name;
  if (previous_object()==this_object()) {
     if (!valid_remote_wiz(wiz_name=p["ASKWIZ"])) GDR_INV(wiz_name);
     else send_rwho_a(p["HOSTADRESS"],to_int(p["PORTUDP"]),p["NAME"],wiz_name);
  }
}

void rwho_a(mapping p) {
object wiz;

  if (previous_object()==this_object())
     if ((wiz=find_player(p["ASKWIZ"])) && wiz->query_level()>L_PLAYER)
        tell_object(wiz,"rwho@"+p["NAME"]+"\n"+p["RWHO"]+"\n",0);
}

void ping_q(mapping p) {
  if (previous_object()==this_object())
     send_ping_a(p["HOSTADRESS"],to_int(p["PORTUDP"]),p["NAME"]);
}

void ping_a(mapping p) {
mixed *host;
string name;

  if (previous_object()==this_object()) {
     if ((name=p["NAME"])==HM) return;		/* Ourselves */
     host=({ p["HOSTADRESS"],
	     to_int(p["PORTUDP"]),
	     p["VERSION"],
	     p["MUDLIB"],
	     p["HOST"],
	     to_int(p["PORT"]),
	     p["TIME"]
	  });
     name=p["NAME"];
     if (!imp_hosts[name]) imp_hosts += ([ name : host]);
     else imp_hosts[name] = host;
  }
}

void gtell(mapping p) {
mixed *host;
string name,wizf,wizt;
object owiz;

  if (previous_object()==this_object()) {
     if ((name=p["NAME"])==HM) return;		/* Ourselves */
     if ((wizt=p["WIZTO"])=="Gamedriver") return;	/* else endless loop */
     if ((wizf=p["WIZFROM"])=="Gamedriver") return;	/* ditto */
     if (!valid_remote_wiz(wizf)) GDR_INV(wizf);
     else {
	if (!(wizt) || !(owiz=find_player(lower_case(wizt))))
		GDR_NLW(wizf);
	else
	    if (!tell_object(owiz,wizf+"@"+name+" tells you: "+p["MSG"]+"\n",0))
		GDR_BSY(wizf);
     }
  }
}

void gfinger_a(mapping p) {
string name,askw;
object owiz;
  if (previous_object()==this_object()) {
     if ((name=p["NAME"])==HM) return;		/* Ourselves */
     if (!(askw) || !(owiz=find_player(lower_case(askw)))) return;
     tell_object(owiz,"rfinger@"+name+":\n"+p["MSG"]+"\n",0);
  }
}

void gwizmsg(mapping p) {

}
#endif

object *get_guild_leader ()
{
    object *u, *leaders, tu;
    int i, ucnt, gcnt, *rating, gnr, trating, tlev; 

    gcnt=sizeof(guild_heads);

    u=users();
    ucnt = sizeof(u);

    leaders=allocate(gcnt);
    rating=allocate(gcnt);
    for(i=0;i<gcnt;i++) rating[i]=0;

    for(i=0;i<ucnt;i++)
    {
        tu = u[i];

        gnr=(int)tu->query_guild();
        tlev=(int)tu->query_level();
        if(tlev > 29 || (int)tu->query_testchar()) continue;

        trating=tlev+(int)tu->query_legend_level()*1000+
                (int)tu->query_perc_advance_lev();

        if(trating > rating[gnr]) 
        {
            rating[gnr] = trating;
            leaders[gnr] = tu;
        };
    }; 
    return leaders;
}

int set_guild_head( int gnr, object o );

mixed get_guild_head( int gnr )
{
    mixed gdata;

    if(gnr<0 || gnr>sizeof(guild_heads)) return 0;

    gdata=guild_heads[gnr];

    if(!gdata) return 0;
    if(get_wiz_level(gdata[0]))
    {
        gdata=guild_heads[gnr]=set_guild_head(gnr, get_guild_leader()[gnr]);
    }
    return gdata;
}

int set_guild_head( int gnr, object o )
{
    string nam;
    int ll, exp;
    mixed gdata;

    return -1;
    if(gnr<0 || gnr>sizeof(guild_heads)) return -1;
    if(!o || !interactive(o)) return -2;
    nam=(string)o->query_real_name();
    gdata=guild_heads[gnr];
    if(!gdata) gdata=({ "", 0, 0 });
    
    if((int)o->query_level()!=29 || (string)o->query_testchar())
    {
        if(nam == gdata[0])
        {
            guild_heads[gnr]=0;
            log_file("HEAD_DEL",nam +" "+(int)o->query_level()+"\n");
            save_object("/secure/WIZSAVE");
        }
        return -3;
    }

    ll=(int)o->query_legend_level();
    exp=(int)o->query_perc_advance_lev();

    if(!guild_heads[gnr])
    {
        guild_heads[gnr]= ({ nam, ll, exp });
	save_object("/secure/WIZSAVE");
        return 2;
    }
    if(ll >= guild_heads[gnr][1] && exp > guild_heads[gnr][2])
    {
        guild_heads[gnr]= ({ nam, ll, exp });
	save_object("/secure/WIZSAVE");
        return 1;
    }
    return -4;
}

#endif // old code for imp_host and such.
