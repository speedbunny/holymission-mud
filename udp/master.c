/*
 * /secure/master.c
 *
 * This is the LPmud master object, used from version 3.0.
 * It is the second object loaded after void.c.
 * Everything written with 'write()' at startup will be printed on
 * stdout.
 * 1. reset() will be called first.
 * 2. flag() will be called once for every argument to the flag -f
 * 	supplied to 'parse'.
 * 3. epilog() will be called.
 * 4. preload() will be called for each file to preload.
 * 5. The game will enter multiuser mode, and enable log in.
 *
 * Sardane added loading of houses here to get root uid
 * Astradyne changed the destructs at finger and used global object (one)
 */

#include "/sys/stdproperties.h"
#include "/sys/macros.h"
#include "/sys/filepath.h"
#include "/sys/udp.h"
#include "/secure/std.h"

#define SAVEFILE	"/syslog/KEEPERSAVE"	/* File to save object in */

/*#define FINGER_LOG      "/open/FINGER"           Who fingerd */

#include "/secure/master/flags.c"
#include "/secure/master/siteban.c"
#include "/secure/master/fob.c"
#include "/secure/master/faircombat.c"
#include "/secure/master/spells.c"
#include "/secure/master/manage_maplinks.c"
#include "/secure/master/language.c"

/* a function to give a shorter date/time output than with ctime(time()): */
#define SHTIME          shorttime()
string shorttime()
{
    string a,b,c,d;
    sscanf(ctime(time()), "%s %s:%s:%s %s",a,b,c,a,d);
    return b+":"+c+" "+d;
}

/*
 * Prototypes
 */
static object find_admin();
static object find_someone(string wiz);
varargs object finger_player(string pl_name, string file);
static int check_snoop_validity(object snooper, object snoopee, int sanction);
varargs mixed do_debug(string icmd, mixed a1, mixed a2, mixed a3);
void linkdead_player(object ob);

object login_ob;
int game_started;
static mapping command_substitute;
static object global_ob, global_ob_2;
mapping known_muds;

int reset() {}
int create() 
{
    command_substitute = ([
			   "n":"north",
			   "s":"south",
			   "w":"west",
			   "e":"east",
			   "u":"up",
			   "d":"down",
			   "sw":"southwest",
			   "se":"southeast",
			   "nw":"northwest",
			   "ne":"northeast",
			   "l":"look",
			   "r":"read",
			  ]);
    call_out("check_memory", 15 * 30);   /* Start Armageddon ? */
}

string short() 
{
    return "the hole in the donut";
}

static varargs int authorization(object pobj, int mintype)
{
    string str;
    int typ, lev;

    if (!pobj)
	return 0;

    if (!mintype)
	mintype = WIZ_ARCH;

    str = geteuid(pobj); lev = query_wiz_level(str); typ = WIZ_TYPE(lev);

    if ((str == get_root_uid()) || (typ >= mintype))
	return 1;

    return 0;
   
}
/*********************************************************************
 *
 * GD - INTERFACE LFUNS
 *
 * The below lfuns are called from the Gamedriver for various reasons.
 */

/*
 * Called on startup of game if '-f' is given on the commandline.
 *
 * To test a new function xx in object yy, do
 * parse "-fcall yy xx arg" "-fshutdown"
 */
void flag(string str) 
{
    string file, arg;

    if (game_started)
	return;

    if (sscanf(str, "for %d", arg) == 1) 
    {
	int i;
	for (i = 0 ; i < arg ; i++) 
	{
	}
	return;
    }

    if (str == "shutdown") 
    {
	do_debug("shutdown");
	return;
    }

    if (sscanf(str, "echo %s", arg) == 1) 
    {
	write(arg + "\n");
	return;
    }
    
    if (sscanf(str, "call %s %s", file, arg) == 2) 
    {
	arg = (string)call_other(file, arg);
	write("Got " + arg + " back.\n");
	return;
    }
    write("master: Unknown flag " + str + "\n");
}

/*
 * Function name:   get_mud_name
 * Description:     Gives the name of the mud. The name will be #defined in
 *		    all files compiled in the mud. It can not contain spaces.
 * Returns:         Name of the mud.
 *		    We always return a string but we must declare it mixed
 *		    otherwise the type checker gets allergic reactions.
 */
mixed
get_mud_name() 
{
#ifdef MUD_NAME    
    mixed n;

    n = MUD_NAME;
    if (mappingp(n))
    {
	if (stringp(n[debug("mud_port")]))
	    return n[debug("mud_port")];
	else
	    return n[0];
    }
    else if (stringp(MUD_NAME))
	return MUD_NAME;
#endif
    return "LPmud(" + do_debug("version") + ":" + MUDLIB_VERSION + ")";
}

/*
 * Function name:   get_root_uid
 * Description:     Gives the uid of the root user
 * Returns:         Name of the 'root' user
 */
string
get_root_uid() 
{
    return "root";
}

/*
 * Function name:   get_bb_uid
 * Description:     Gives the uid of the backbone
 * Returns:         Name of the 'backbone' user
 */
string
get_bb_uid()
{
    return "backbone";
}

/*
 * This function is called every time a player connects.
 * input_to() can't be called from here.
 */
object
connect() 
{
    /* write("secure/master: Connect to /secure/login.c..."); */
    seteuid(get_root_uid());
    login_ob = clone_object("/secure/login");
    write("\n");
    return login_ob;
}

/*
 * Function name:   valid_seteuid
 * Description:     Checks if a certain user has the right to set a certain
 *                  objects effective 'userid'. All objects has two 'uid'
 *                  - Owner userid: Wizard who caused the creation.
 *                  - Effective userid: Wizard responsible for the objects
 *                    actions.
 *                  When an object creates a new object, the new objects
 *                  'Owner userid' is set to creating objects 'Effective
 *                  userid'.
 *                  
 * Arguments:       ob:   Objekt to set 'effective' user id in.
 *                  str:  The effuserid to be set.
 * Returns:         True if set is allowed.
 * Note:	    Setting of effuserid to userid is allowed in the GD as
 *		    well as setting effuserid to 0.
 */
int
valid_seteuid(object ob, string str) 
{
    /*
     * Root can be anyone it pleases.
     */
    if (getuid(ob) == get_root_uid())
	return 1;

    /*
     * We can be ourselves, why we have to check this... well...
     */
    if (getuid(ob) == str)
	return 1;

    /*
     * When arches and keepers are in a domain, the lord can't change
     * euid in his objects to the arch.
     */
    if (query_wiz_level(str) > WIZLEV_LORD)
	return 0;

    /*
     * A lord can be anyone of his subject wizards.
     */
    if (getuid(ob) == query_domain_lord(str) 
	|| getuid(ob) == query_domain_lord(query_wiz_dom(str)))
	return 1;

    return 0;
}

/*
 * This is the function called from the game driver when it wants to know
 * if it has permission to write in file 'file_name' with effective user
 * 'eff_user'. The return value is simply true or false.
 *
 */

/*
 * Function name:   valid_write
 * Description:     Checks if a certain user has the right to write a file
 * Arguments:       file - File name of the file to be written
 *                  eff_user - Name of the wizard responsible for the write.
 *		    func - The calling function.
 * Returns:         True if write is allowed.
 */
int
valid_write(string file, string eff_user, string func) 
{
    string junk, dom, dir, sanct;
    string *dirs, *open_dir;
    int i, flag;
    object wob;

    /* write("VALID_WRITE, File name: " + file + ", effective user: " +
	     eff_user + ", caller: " + func + "\n");
    */

    dirs = explode(file + "/", "/");

    /* 
     * All paths should be resolved before this.
     */
    if ((member_array("..", dirs) >= 0) ||
	(member_array("", dirs) >= 0) ||
	(member_array(".", dirs) >= 0))
	return 0;

    /* 
     * Anonymous objects can`t do anything.
     */
    if(eff_user == 0)
	return 0;

    /*
     * Root, keepers & arches can always do as they please.
     */
    if (eff_user == get_root_uid() || 
	(query_wiz_level(eff_user) > WIZLEV_LORD))
        return 1;

    /*
     * You can always write in /ftp and /open.
     */
    if ((dirs[0] == "ftp") ||
	(dirs[0] == "open"))
	return 1;

    /*
     * Any object can log stuff. But only in /log.
     *
     * This part is removed, because the game driver is change to
     * skip checks in log_file, since it always prepends /log.
     */

    /* 
     * Must be /d/Domname/something
     */
    if (sizeof(dirs) < 3)  
	return 0;

    /*
     * Domain writes.
     */
    if (dirs[0] != "d")
	return 0;

    dom = dirs[1];

    if (sizeof(dirs) > 3) 	/* Can be /d/domname/dirname/something */
	dir = dirs[2];
    else
	dir = "";

    /*
     * Domain lords can write anywhere in their domains.
     */
    if (eff_user == query_domain_lord(dom))
	return 1;

    /*
     * A wizard can write in his directory.
     */
    if (eff_user == dir)
	return 1;

    /*
     * The special wizard domain has no special dirs such as open / common
     */
    if (dom == WIZARD_DOMAIN)
	return 0;

    /*
     * A wizard can write in the domain directories that is not wiz dirs.
     */
    if ((query_wiz_dom(eff_user) == dom || eff_user == dom) && 
	query_wiz_dom(dir) != dom)
	return 1;

#ifdef OPEN_WRITE
    /*
     * Special patch for write access in public domains
     */
    if (stringp(OPEN_WRITE[eff_user]))
    {
	/*
	 * Write access in all of the open domain.
	 */
	if (!strlen(OPEN_WRITE[eff_user]))
	    return 1;

	/*
	 * Determine if the path is right.
	 */
	open_dir = explode(OPEN_WRITE[eff_user], "/");
	flag = 1;
	if (sizeof(dirs) > 2 + sizeof(open_dir) && 
	    member_array(dom, OPEN_DOMAINS) >= 0)
	{
	    for (i = 0 ; i < sizeof(open_dir) ; i++)
	    {
		if (open_dir[i] != dirs[i + 2])
		{
		    flag = 0;
		    break;
		}
	    }
	    if (flag)
		return 1;
	}
    }
#endif
    
    /* 
     * A wizard can sanction another wizard(type) to read in his directory.
     * A lord can sanction another wizard(type) to read in his directory.
     * Check that the domain is right as well as read privs.
     * We must be under a wiz subdir to be able to do this at all.
     */
    wob = find_player(dir);
    if (!wob)
    {
	wob = finger_player(dir);
	if (!wob)
	    return 0;
	sanct = (string)wob->query_sanctioning(eff_user);
	/* destruct(wob); Hope we dont need this anymore */
    }
    else
	sanct = (string)wob->query_sanctioning(eff_user);

    if (strlen(sanct) && query_wiz_dom(dir) == dom)
    {
	for (i = 0 ; i < strlen(sanct) ; i++)
	    if (sanct[i] == 'w')
		return 1;
    }

    return 0;
}

/*
 * Function name:   valid_read
 * Description:     Checks if a certain user has the right to read a file
 * Arguments:       file - File name of the file to be read
 *                  eff_user - Name of the wizard responsible for the read.
 *		    func - The calling function.
 * Returns:         True if read is allowed.
 */
int
valid_read(string file, string eff_user, string func) 
{
    string dom, wname, dir, sanct;
    string *dirs;
    object wob;
    int i;

    dirs = explode(file + "/", "/");

    /* 
     * All paths should be resolved before this.
     */
    if ((member_array("..", dirs) >= 0) ||
	(member_array("", dirs) >= 0) ||
	(member_array(".", dirs) >= 0))
	return 0;

    /* 
     * Anonymous objects can`t do anything.
     */
    if(eff_user == 0)
	return 0;

    /*
     * Root, keepers & arches can always do as they please.
     */
    if (eff_user == get_root_uid() || 
	(query_wiz_level(eff_user) > WIZLEV_LORD))
        return 1;

     /*
     * Allow read i /
     */
    if (sizeof(dirs) < 2)
	return 1;

    /*
     * Check for the "closed" directories.
     */
    if ((dirs[0] == "op") ||
	(dirs[0] == "players") ||
	(dirs[0] == "bin"))
	return 0;

    /*
     * Allow read in all that is not /d
     */
    if (dirs[0] != "d")
	return 1;

    dom = dirs[1];
    if (sizeof(dirs) > 2)
	wname = dirs[2];
    if (sizeof(dirs) > 3)
	dir = dirs[3];

#ifdef OPEN_DOMAINS
    /* 
     * This is the Domains open to public read
     */
    if (member_array(dom,OPEN_DOMAINS) >= 0)
	return 1;
#endif

    /*
     * Anyone can read in the domain and wizards open directory.
     */
    if ((dir == "open") || (wname == "open"))
	return 1;

#ifdef GLOBAL_READ
    /* 
     * These are specific users, that for some reason or other should
     * be able to read anywhere. Specific examples are local users that
     * can read the files outside the mud anyway.
     */
    if (member_array(eff_user,GLOBAL_READ) >= 0)
	return 1;
#endif

    /*
     * All wizards in the domain can read everything in the domain.
     * unless it is the 'lonely wizard' domain. Then each wizard can only
     * read his own files.
     */
    if ((query_wiz_dom(eff_user) == dom) || (eff_user == dom)) {
	if (dom != WIZARD_DOMAIN)
	    return 1;
	else if (wname == eff_user)
	    return 1;
	else
	    return 0;
    }

    /* 
     * A wizard can sanction another wizard to read in his directory.
     * Check that the domain is right as well as read privs.
     * We must be under a wiz subdir to be able to do this at all.
     */
    sanct = 0;

    if (strlen(wname))
    {
	wob = find_player(wname);
	if (!wob)
	{
	    if (wob = finger_player(wname))
	    {
		sanct = (string) wob->query_sanctioning(eff_user) +
		    wob->query_sanctioning(WIZ_LEV_NAME(query_wiz_level(eff_user)));
		/* destruct(wob); use the same object each time P-) */
	    }
	}
	else
	    sanct = (string) wob->query_sanctioning(eff_user) +
		wob->query_sanctioning(WIZ_LEV_NAME(query_wiz_level(eff_user)));
	
	if (strlen(sanct) && query_wiz_dom(wname) == dom)
	{
	    for (i = 0 ; i < strlen(sanct) ; i++)
		if (sanct[i] == 'r')
		    return 1;
	}
    }
    wob = find_player(query_domain_lord(dom));
    if (!wob)
    {
	if (wob = finger_player(query_domain_lord(dom)))
	{
	    sanct = (string) wob->query_sanctioning(eff_user) +
		wob->query_sanctioning(WIZ_LEV_NAME(query_wiz_level(eff_user)));
	    /* destruct(wob); no need */
	}
    }
    else
	sanct = (string) wob->query_sanctioning(eff_user) +
	    wob->query_sanctioning(WIZ_LEV_NAME(query_wiz_level(eff_user)));

    if (strlen(sanct))
    {
	for (i = 0 ; i < strlen(sanct) ; i++)
	    if (sanct[i] == 'R')
		return 1;
    }

    return 0;
}

/*
 * Function name:   valid_trace
 * Description:     Checks if a certain user has the right to use trace
 *		    This can be used to minimize the cost of trace if it
 *		    is only to be used by some higher level wizards.
 * Arguments:       ob: Object that wants to set trace
 *                  param: Either a string or a number, if a string then it
 *			   is a call from efun traceprefix(), if a number other
 *			   then '0' the it is a call from trace()
 * Returns:         True if use is allowed.
 */
int
valid_trace(object ob, mixed param)
{
    return 1;
}

/*
 * Function name:   valid_snoop
 * Description:     Checks if a certain user has the right to use snoop
 *		    another user.
 * Arguments:       snooper: The prospective snooper.
 *		    snopee: The prospective snoopee.
 * Returns:         True if use is allowed.
 */
public int
valid_snoop(object snooper, object snoopee)
{
    string by_name, po_name;

    by_name = geteuid(snooper);
    po_name = geteuid(previous_object());

    /* 
     * Break snoop case:
     *
     * Valid if previous_object() (= breaker) has the right to
     * snoop the person currently doing the snooping.
     * Do not consider sanctioning in this case.
     */
    if (!snoopee)
    {
	/*
	 * Anyone can break his own snoop.
	 */
	if (by_name == po_name)
	    return 1;

	return check_snoop_validity(previous_object(), snooper, 0);
    }

    /*
     * Prevent accidental breaking of snoop.
     */
    if (efun::query_snoop(snoopee))
	return 0;

    /* 
     * Set up snoop case:
     *
     * Valid if previous_object() (= the one setting up the snoop) has
     * the right to snoop the snoopee.
     * Make sure this does not break a snoop though.
     * Do not consider sanctioning in this case.
     */
    if (po_name != by_name)
	return check_snoop_validity(previous_object(), snoopee, 0);
    
    /*
     * Ordinary snoop case:
     *
     * Valid if snooper can snoop snoopee.
     * Consider sanctioning in this case.
     */
    return check_snoop_validity(snooper, snoopee, 1);
}

/*
 * Function name:   check_snoop_validity
 * Description:     Do the actual validity checking.
 * Arguments:       snooper: The prospective snooper.
 *		    snopee: The prospective snoopee.
 *		    sanction: Consider sanctioning or not.
 * Returns:         True if use is allowed.
 */
static int
check_snoop_validity(object snooper, object snoopee, int sanction)
{
    int by_type, on_type;
    string by_name, on_name, sanct;
    object wob;
    int i;

    by_type = WIZ_TYPE(query_wiz_level(geteuid(snooper)));
    by_name = geteuid(snooper);
    on_type = WIZ_TYPE(query_wiz_level(geteuid(snoopee)));
    on_name = geteuid(snoopee);
    
    /*
     * Only wizards can snoop.
     */
    if (by_type == WIZ_MORTAL)
	return 0;

    /*
     * Lords can snoop members everywhere, 
     * if the snoopee has lvl < ARCH 
     */
    if (by_type == WIZ_LORD && 
	query_domain_lord(query_wiz_dom(on_name)) == by_name &&
	on_type < WIZ_ARCH)
	return 1;

    /*
     * Arch snoops all but arch.
     */
    if (by_type >= WIZ_ARCH && on_type < WIZ_ARCH)
	return 1;

    /* 
     * Mortals are safe in sanctuary for all but arch++.
     */
    if (environment(snoopee)->query_prevent_snoop())
	return 0;

    /*
     * Ordinary wizzes snoops all mortals.
     */
    if (on_type == WIZ_MORTAL)
	return 1;

    /* 
     * A wizard can sanction another wizard to snoop him.
     * Check that the domain is right as well as read privs.
     * We must be under a wiz subdir to be able to do this at all.
     */
    if (sanction)
    {
	wob = find_player(on_name);
	if (!wob)
	{
	    wob = finger_player(on_name);
	    sanct = wob->query_sanctioning(by_name);
	    /* destruct(wob); */
	}
	else
	    sanct = wob->query_sanctioning(by_name);
	
	if (strlen(sanct))
	{
	    for (i = 0 ; i < strlen(sanct) ; i++)
		if (sanct[i] == 's')
		    return 1;
	}
    }

    return 0;
}

/*
 * Function name:   creator_file
 * Description:     Gives the name of the creator of a file. This is a
 *                  direct function of the file_name().
 * Returns:         Name of the creator
 */
string creator_file(string file)
{
    string str, dom, wiz, residue;

    str = file;

    if (str[0] != '/')
	str = "/" + str;

    /* 
     * Domains: return the wizard name if the file is resident in
     * the directory of an active (not retired) wizard.
     * If the directory is "open" or "common", the domain is set 
     * to be the creator. Return the name of the Lord otherwize.
     */
    if ((str[1] == 'd') && (str[2] == '/'))
    {
	if (sscanf(str, "/d/%s/%s/%s", dom, wiz, residue) == 1) {
	    sscanf(str, "/d/%s/%s", dom, residue);
	    wiz = 0;
	}

	if ((wiz) && (query_wiz_dom(wiz) == dom))
	    return wiz;
	else
	    return dom;
    }

    /* 
     * /secure/... return root uid.
     */
    if (sscanf(str, "/secure/%s", residue) == 1)
	return (string)SECURITY->get_root_uid();

    /*
     * No cloning or loading from /ftp or /open.
     */
    if (sscanf(str, "/ftp/%s", residue) || sscanf(str, "/open/%s", residue))
	return 0;

    /*
     * All else: return backbone uid.
     */
    return (string)SECURITY->get_bb_uid();

}

/*
 * Convert a possibly relative path to an absolute path. We can assume
 * that there is a this_player(). This is called from within the editor.
 */
string 
make_path_absolute(string path)
{
    return FPATH(this_player()->query_path(), path);
}

/*
 * Function name: 	epilog()
 * Description:		Loads master data, including list of all domains and
 *			wizards. Then make a list of preload stuff
 * Arguments:		load_empty: If true epilog() does no preloading
 * Return:		List of files to preload
 */
string *
epilog(int load_empty)
{
    string *prefiles;
    object simf;

    if (game_started)
	return 0;

    /*
     * This builds a mapping of all functions in the object, speeding up
     * calls to this object significantly.
     */
    debug("function_map", 1, this_object());

    /*
     * Fix the userids of the simul_efun object
     */
    simf = find_object("/secure/simul_efun");
    if (simf)
    {
	export_uid(simf);
	simf->fixeuid();
	/*
	 * This builds a mapping of all functions in the object, speeding up
	 * calls to this object significantly.
	 */
	debug("function_map", 1, simf);
    }

    write("Retrieving master data.\n");
    if (!restore_object(SAVEFILE))
    {
	write(SAVEFILE + " nonexistant. Using defaults.\n");
	this_object()->load_fob_defaults();
    }
    game_started = 1;
    this_object()->setup_maplinks();

#ifdef UDP_MANAGER
    UDP_MANAGER->send_startup_udp(MUDLIST_SERVER[0], MUDLIST_SERVER[1]);
#else
    debug("send_udp", MUDLIST_SERVER[0], MUDLIST_SERVER[1],
	  "@@@" + UDP_STARTUP + this_object()->startup_udp() + "@@@\n");
#endif


    if (load_empty) 
    {
	write("Not preloading.\n");
	return 0;
    }
    
    /* 
     * Make list of preload stuff: Domain and wizard
     * 		
     */
    prefiles = query_domain_preload() + query_mage_preload() + ({ DEFAULT_START });
    write_file("/GAME_START", ctime(time()));
    return prefiles;
}

void
preload(string file)
{
    string err;
    int t1;

    seteuid(get_root_uid());   /* Make filesize always succeed */

    if (file_size(file + ".c") == -1)
	return;

    err = creator_file(file);
    seteuid(err);
    write(file + ".c (" + err + ")\n"); 

    if (err = (string)LOAD_ERR(file))
	write("\tCan not load: " + file + ":\n     " + err + "\n");
}

/*
 * Get the owner of a file. This is called from log_error(), so as
 * to be able to know which wizard should have an error message.
 * Some checks should be added to take care of the domain file tests.
 *
 */
/* This function is no longer used by the GD. But it is used once in this
 * file. It should be relocated
 */
string get_wiz_name(string file)
{
    string name, dom;

    return creator_file(file);
}

/*
 * Calculate a path for the logging of an error.
 */
string get_log_file(string file)
{
    string name, path;

    name = creator_file(file);
    path = query_wiz_path(name) + "/log";
    seteuid(get_root_uid());

    if (file_size(path) != -2) 
	mkdir(path);

    return path + "/errors";
}

/*
 * Write an error message into a log file. The error occured in the object
 * 'file', giving the error message 'message'.
 */
void log_error(string file, string message)
{
    string name;

    name = get_log_file(file);
    if (name == 0)
        name = "/log/LOST_ERRORS";
    seteuid(get_root_uid());
    if (file_size(name) == -1)
	write_file(name, "*\n* This is your error log file\n*\n\n");
    write_file(name, message);
}

/*
 * This function is called for a wizard that has dropped a castle.
 * The argument is the file name of the object that called create_wizard().
 * Verify that this object is allowed to do this call.
 */
int verify_create_wizard(object ob)
{
    return file_name(ob) == "secure/master";
}

/*
 * This function is called from GD when rooms are destructed so that master
 * can move players to safety.
 */
void
destruct_environment_of(object ob)
{
    if (environment(ob))
	catch(ob->move(environment(ob)));

    if (!query_ip_number(ob))
	return;
    ob->move_living("X",ob->query_default_start_location());
}

/*
 * Define  where the '#include' statement is supposed to search for files.
 * "." will automatically be searched first, followed in order as given
 * below. The path should contain a '%s', which will be replaced by the file
 * searched for.
 */
string *
define_include_dirs()
{
    return ({ "/sys/%s", "/secure/%s" });
}

/*
 * Give a file name for edit preferences to be saved in.
 */
string get_ed_buffer_save_file_name(string file) 
{
    if (this_player())
    {
	return query_wiz_path(this_player()->query_real_name()) + 
	"/.dead_ed_files/"+file;
    }
    else
	return 0;
}

/* save_ed_setup and restore_ed_setup are called by the ed to maintain
   individual options settings. These functions are located in the master
   object so that the local gods can decide what strategy they want to use.

/*
 * The wizard object 'who' wants to save his ed setup. It is saved in the
 * file ~wiz_name/.edrc . A test should be added to make sure it is
 * a call from a wizard.
 *
 * Don't care to prevent unauthorized access of this file. Only make sure
 * that a number is given as argument.
 */
int save_ed_setup(object who, int code)
{
    string file;

    if (!intp(code))
	return 0;
    file = query_wiz_path((string)who->query_real_name()) + "/.edrc";
    rm(file);
    return write_file(file, code + "");
}

/*
 * Retrieve the ed setup. No meaning to defend this file read from
 * unauthorized access.
 */
int retrieve_ed_setup(object who) {
    string file;
    int code;

    file = query_wiz_path((string)who->query_real_name()) + "/.edrc";
    if (file_size(file) <= 0)
	return 0;
    sscanf(read_file(file), "%d", code);
    return code;
}

/*
 * The master object is asked if it is ok to shadow object ob. Use
 * previous_object() to find out who is asking.
 *
 * In this example, we allow shadowing as long as the victim object
 * has not denied it with a query_prevent_shadow() returning 1.
 */
int query_allow_shadow(object ob)
{
    if (ob == this_object())
	return 0;

    return !ob->query_prevent_shadow(previous_object());
}


/*
 * There are several occasions when the game driver wants to check if
 * a player has permission to specific things.
 *
 * These types are implemented so far:
 * "error messages":	If the player is allowed to see runtime error
 *			messages.
 * "trace":		If the player is allowed to use tracing.
 * "wizard":		Is the player considered at least a "minimal" wizard ?
 * "error messages":	Is the player allowed to get run time error messages ?
 */
int query_player_level(string what)
{
    int level;

    if (this_player() == 0)
	return 0;
    level = (int)this_player()->query_wiz_level();
    switch(what) {
    case "wizard":
	return level >= 1;
    case "error messages":
	return level >= 1;
    case "trace":
	return level > WIZLEV_LORD;
    }
}

/*
 * Function name:   valid_exec
 * Description:     Checks if a certain 'program' has the right to use exec()
 * Arguments:       name: Name of the 'program' that attempts to use exec()
 *                        Note that this is different from file_name(),
 *                        Programname is what 'function_exists' returns.
 *                  NOTE, the absence of a leading slash in the name.
 * Returns:         True if exec() is allowed.
 */
int
valid_exec(string name)
{
    if (name == "secure/login.c" || 
	name == "std/possob.c" ||
	name == (extract(LOGIN_NEW_PLAYER,1) + ".c"))
	return 1;

    return 0;
}

/*
 * Function name:   approve_object
 * Description:     Separates approved and nonapproved objects.
 *                  Approved and nonapproved objects can not be mixed
 *		    with move_object().
 * Arguments:       ob: The object to check on
 * Returns:         1 if object approved.
 */
int
approve_object(object ob)
{
    if (function_exists("create", ob) == "/std/object")
	return 1;
    else
	return 0;
}

/*
 * Function name:   modify_command
 * Description:     Modify a command given by a certain living object.
 *                  This can be used for many quicktyper-like functions.
 *		    There is also some master.c defined substitutions.
 * Arguments:       cmd: string
 *                  ob: The object for which to modify the command
 * Returns:         The modified command to execute
 */
string
modify_command(string cmd, object ob)
{
    string str;
    if (str = command_substitute[cmd])
	return str;

    /* We can not allow any handwritten VBFC
    */
    if (sscanf(" " + cmd + " ", "%s@@%s", str, str) == 2)
	cmd = implode(explode(cmd, "@@"), "#");

    if (!interactive(ob))
	return cmd;   /* Currently no modification */
    else
	return ob->modify_command(readable_string(cmd));
}

/*
 * Function name:   memory_failure
 * Description:     This function is called when the gamedriver considers
 *                  itself in trouble and need the game shut down in a
 *		    graceful manner,
 */
string
memory_failure()
{
    call_other(ARMAGEDDON, "slow_shut"); /* We start Armageddon! */
}

/*
 * Function name:   valid_save_binary
 * Description:     This function is called when a file has ordered the GD
 *                  to save a binary image of the program. This might not
 *		    be allowed by any and every file so master is asked.
 * Arguments:       file: Filename of the object.
 */
int 
valid_save_binary(string filename)
{
    return 1;
}

/*
 * Function name:   master_reload
 * Description:     Called from GD after a reload of the master object
 */
void
master_reload()
{
    (void)epilog(1); /* This does what we want */
}

/*
 * Function name:   incoming_udp
 * Description:     Called from GD if a udp message has been received. This
 *		    can only happen if CATCH_UDP_PORT has been defined in
 *		    the GD's config.h file.
 * Arguments:	    from_host: The IP number of the sending host
 *		    message:   The message sent.
 */
void
incoming_udp(string from_host, string message)
{
#ifdef UDP_MANAGER
    UDP_MANAGER->incoming_udp(from_host, message);
#endif
}
 
/* 
 *    ----------------------------------------------------------------
 *    The code below this divisor is never called from the gamedriver.
 *    ----------------------------------------------------------------
 */


/*
 * Function name:   creator_object
 * Description:     Gives the name of the creator of an object. This is a
 *                  direct function of the file_name() of the object.
 * Returns:         Name of the wizard / domain
 */
string
creator_object(object obj)
{
    string ret;

    if (objectp(obj))
	ret = creator_file(MASTER_OB(obj));
    else
	ret = 0;

    /* write("File: " + file_name(obj) + ", Creator: " + ret + "\n"); */
    return ret;
}

/*
 * Function name:   domain_object
 * Description:     Gives the name of the domain of an object. This is a
 *                  direct function of the file_name() of the object.
 * Returns:         Name of the domain
 */
string
domain_object(object obj)
{
    string str,dom,wiz,name;

    str = file_name(obj);
    if (str[1] == 'd')
	sscanf(str,"/d/%s/%s/%s",dom,wiz,name);
    else
	dom = 0;
    return dom;
}


/*
 * Function name: load_old_player
 * Descripton:    This function is called from the login player object
 *                /std/player_sec when the player object is loaded initially. 
 *                It sets the euid of the player to root for 
 *                the duration of the load.
 */
object
load_old_player(string oldplayer_filename)
{
    int res;
    object pobj, op;
    string oname;

    pobj = previous_object();

    if (function_exists("load_player", pobj) !=  "/std/player_sec")
	return 0;

    oname = pobj->query_real_name();

    if ((file_size("/op/" + extract(oname, 0, 0) + "/" + oname + ".o") <= 0) &&
	(file_size("/op/" + oname + ".o") <= 0))
	return 0;

    op = clone_object(oldplayer_filename);

    if (!op)
	return 0;

    seteuid(get_root_uid());
    export_uid(op);

    if (!op->enter_here(pobj->query_real_name()))
    {
	write("Couldn't restore your old character.\n");
	destruct(op);
	return 0;
    }
    seteuid(creator(op));
    export_uid(op);

    return op;
}

/*
 * Function name: load_player
 * Descripton:    This function is called from /std/player_sec 
 *		  when the player object is loaded initially. 
 *                It sets the euid of the player to root for 
 *                the duration of the load.
 */
int
load_player()
{
    int res;
    object pobj;

    pobj = previous_object();

    if (function_exists("load_player", pobj) !=  "/std/player_sec" ||
	!LOGIN_NEW_PLAYER->legal_player(pobj))
	return 0;
    else
    {
	seteuid(get_root_uid());
	export_uid(pobj);
	res = (int)pobj->load_player(pobj->query_real_name());
	seteuid((pobj->query_wiz_level() ?
			  (string) pobj->query_real_name() : get_bb_uid()));
	export_uid(pobj);
	seteuid(get_root_uid());
	return res;
    }
}

/*
 * Function name:   save_player
 * Description:     Saves a player object.
 */
int
save_player()
{

    int res;
    object pobj;

    pobj = previous_object();
    
    if (function_exists("save_player", pobj) !=  "/std/player_sec" ||
	!LOGIN_NEW_PLAYER->legal_player(pobj))
	return 0;
    else
    {
	seteuid(get_bb_uid());
        pobj->fix_saveprop_list();
	seteuid(get_root_uid());
	export_uid(pobj);
	res = (int)pobj->save_player(pobj->query_real_name());
	pobj->open_player();
	seteuid(pobj->query_wiz_level() ?
			  (string)pobj->query_real_name() : get_bb_uid());
	export_uid(pobj);
	seteuid(get_root_uid());
	return res;
    }
}

/*
 * Function name:   load_wiz_souls
 * Description:     Load the correct wizard souls for the player
 */
int
load_wiz_souls()
{

    int res;
    object pobj;

    pobj = previous_object();

    if ((function_exists("enter_game", pobj) !=  "/std/player_sec") &&
	(pobj != this_object()))
	return 0;
    else
	pobj->load_wiz_souls();
}

/*
 * We have some arrays containing legal starting places. We have to restore
 * them before doing the actual check.
 */

string *def_locations, *temp_locations;


/*
 * Info should exist on this object but we do not want to inherit 
 * the entire /std/object
 */
mixed
query_prop(string str)
{
    if (str == OBJ_S_WIZINFO)
	return "This is the master object, it handles administration and security\n";
    else
	return 0;
}

object
check_caller()
{
    return this_object();
}

int
check_set_sponsor(mixed called_by_object)
{
    return 0;
}

/*
 * Function name: check_inherit
 *                Checks if an object is legal.
 *                file: File name of inherited file
 *                obj:  The object doing the inherit
 */
int
check_inherit(string file, mixed obj)
{
    /*
     * Rules /std/living only /std/player_sec, /std/npc
     * /std/player_sec only /std/player_pub
     */
    return 0;
}

/*
 * Function name: notify_error
 * Description:   Notify player and creator of the offending object
 *      	  that an error has occured.
 * Arguments:     where: In which routine the error occured,
 *		  err:   The error message to the creator.
 *		  info:  Optional extra information to the creator.
 */
void
notify_error(mixed where, string err, string info)
{
}

/* 
   Called from move when a destination room can not be loaded
   Logs the error in /log/wizname.name, /log/domainname.room
   and /log/room.ERRORS If the wiz is logged in then he gets the error too
*/
void
log_loaderror(string efile, mixed from, string verb, mixed pobj, string erl)
{
    string          wiz,
                    player,
                    emsg,
                    lfile1, lfile2,
                    gdriverror;
    object          pl;

    /*
     * Find the responsible wizard or someone else if wiz is not logged in
     */
    
    wiz = creator_object(pobj);
    if ((!wiz) || (wiz == get_bb_uid()))
    {
	wiz = "backbone";
	pl = find_admin();	/* Tell Gameadmin when error in /room */
	lfile1 = 0;
	lfile2 = 0;
    }
    else {
	pl = find_player(wiz);
	lfile1 = FPATH("/log",get_wiz_name(file_name(pobj))) + ".move";
	if ((domain_object(pobj)) && (query_wiz_level(wiz)))
	    lfile2 = "/d/" + domain_object(pobj) + "/common/errors.move.wiz";
	else
	    lfile2 = 0;
    }

    if ((!pl) && (this_player()) && (this_player()->query_wiz_level()))
	pl = this_player();

    if (!pl)
	pl = find_someone(wiz);	/* Tell someone else if wiz not logged in */

    /*
     * Find the name of the player or object that tried to move
     */
    if (!this_player())
	player = "(NULL,Prev: " + file_name(pobj) + ")";
    else
	player = capitalize((string) this_player()->query_real_name()) + " (Level: " +
	    (int) this_player()->query_average() + ")";

    /*
     * Construct error message
     */
    emsg = " Player: " + player + ", from:\n (" + file_name(from);
    if (from != pobj)
	emsg += ":by:" + file_name(pobj);
    emsg += ") " + verb + " to (" + efile + ")";
    gdriverror = (string)LOAD_ERR(efile);
    if (!gdriverror)
    {
	gdriverror = " In reset(): " + erl;
    }
    else
	gdriverror = "Can't load object: " + erl;

    /*
     * Tell the player that he encountered an error
     */
    if ((this_player()) && (pl != this_player()))
    {
	write("** Error **\n");
	write("Due to a slight mistake in this Creation you can't move there.\n");
	write("The creator responsible has been notified of this and will fix it.\n");
    }

    /*
     * Log the error in three files: wizname.room domainname.room and
     * room.ERRORS
     */
    if ((pl) && (pl->err_report(wiz, 0)))
	player = "[Told: " + capitalize((string) pl->query_real_name()) + "]";
    else
	player = "[LOGONLY]";

    if (lfile1)
	write_file(lfile1, player + ctime(time()) + " " + emsg +
	     "\nErr: " + gdriverror + "\n");
    
    if (lfile2)
	write_file(lfile2, player + ctime(time()) + " " + emsg +
		   "\nErr: " + gdriverror + "\n");

    log_file("Move_errors", player + " " + ctime(time()) + " " + emsg +
	     "\nErr: " + gdriverror + "\n");

    /*
     * Tell the wizard he has a bug in his code, or tell someone else.
     */
    if (pl)
    {
	if (wiz == (string)pl->query_real_name())
	    wiz = "your";
	else if (pl == this_player())
	    wiz = capitalize(wiz + "'s");
	else
	{
	    wiz = capitalize(wiz + "'s");
	    pl->err_report(wiz, "The below wizard is not logged in, you get it this report in stead:\n");
	}
	pl->err_report(wiz, "\nError in " + wiz + " room files, the move was:\n");
	pl->err_report(wiz, emsg + "\n");
	pl->err_report(wiz, "The error given by the Game Driver was:\n" + gdriverror + "\n");
    }
}

/* 
   Find someone else to tell the error to:
   1) The domain lord
   2) Someone else in the domain
   3) Mage / Arch
   4) Another domainlord
*/
static object
find_someone(string wiz)
{
    object          apa;
    object          *bepa;
    string          dom,
                    dlord;

    dom = query_wiz_dom(wiz);	/* Find the domain of the wizard */
    dlord = query_domain_lord(dom);

    apa = find_player(dlord);
    if (apa->err_report("other", 0))
	return apa;

    bepa = filter(users(), "qf_domain", this_object(), dom);
    if (bepa)
	return bepa[random(sizeof(bepa))];

    bepa = filter(users(), "qf_arch", this_object());
    if (bepa)
	return bepa[random(sizeof(bepa))];

    bepa = filter(users(), "qf_lord", this_object());
    if (bepa)
	return bepa[random(sizeof(bepa))];
    return 0;
}

static int
qf_domain(mixed ob, string dom)
{
    if ((string)ob->query_domain() != dom)
	return 0;
    if (ob->err_report("other", 0))
	return 1;
    return 0;
}

static int
qf_arch(mixed ob)
{
    if (WIZ_TYPE(ob->query_wiz_level()) < WIZ_MAGE)
	return 0;
    if (ob->err_report("other", 0))
	return 1;
    return 0;
}

static int
qf_lord(mixed ob)
{
    if (WIZ_TYPE(ob->query_wiz_level()) < WIZ_LORD)
	return 0;
    if (ob->err_report("other", 0))
	return 1;
    return 0;
}

static object
find_admin()
{
    object *apa;

    apa = filter(users(), "qf_admin", this_object());
    if (apa)
	return apa[random(sizeof(apa))];
    return 0;
}

static int
qf_admin(mixed ob)
{
    if (WIZ_TYPE(ob->query_wiz_level()) < WIZ_KEEPER)
	return 0;
    if (ob->err_report("other", 0))
	return 1;
    return 0;
}

int
add_def_start_loc(string str)
{
    if (!def_locations)
	def_locations = STARTING_PLACES;
    
    if (WIZ_TYPE(MYLEV) < WIZ_ARCH)
    {
	write("Only arches or keepers may add starting locations.\n");
	return 1;
    }
    
    seteuid(get_root_uid());
    if (file_size(str + ".c") < 0)
    {
	write("No such file: " + str + "\n");
	return 1;
    }
    while (member_array(str, def_locations) >= 0) /* Delete copies */
	def_locations = def_locations - ({ str });

    def_locations = def_locations + ({ str });
    save_object(SAVEFILE);
}

int
add_temp_start_loc(string str)
{
    if(!temp_locations)
	temp_locations = TEMP_STARTING_PLACES;
    
    if (WIZ_TYPE(MYLEV) < WIZ_ARCH)
    {
	write("Only arches or keepers may add starting locations.\n");
	return 1;
    }
    seteuid(get_root_uid());
    if (file_size(str + ".c") < 0)
    {
	write("No such file: " + str + "\n");
	return 1;
    }
    while (member_array(str, temp_locations) >= 0) /* Delete copies */
	temp_locations = temp_locations - ({ str });

    temp_locations = temp_locations + ({ str });
    save_object(SAVEFILE);
}

public string *
query_list_def_start()
{
    if (SECURE_ARRAYS)
	return slice_array(def_locations,0,sizeof(def_locations));
    else
	return def_locations;
}

public string *
query_list_temp_start()
{
    if (SECURE_ARRAYS)
	return slice_array(temp_locations,0,sizeof(temp_locations));
    else
	return temp_locations;
}

int
check_temp_start_loc(string str)
{
    return member_array(str, temp_locations);
}

int
check_def_start_loc(string str)
{
    if (!def_locations)
	def_locations = STARTING_PLACES;
    return member_array(str, def_locations);
}

void
log_from_login(string file, string text) {

    if(extract(file_name(previous_object()), 0, 12) != "/secure/login")
	return;
    seteuid(get_root_uid());
    log_file(file, text);
}
	



/*
 * Function name:   exist_player
 * Description:     Checks if a player exist or not
 * Arguments:	    pl_name: Name of player
 * Returns:         True if player exist.
 */
#ifdef UNDEF
int
exist_player(string pl_name)
{
    object ob;
    int ret;
    
    seteuid(get_bb_uid());
    ob = clone_object(DEFAULT_PLAYER);
    ob->master_set_name(pl_name);
    ob->open_player();               /* Sets euid == 0 */
    seteuid(get_root_uid());
    export_uid(ob);
    ret = (int) ob->load_player(pl_name);
    destruct(ob);
    return ret;
}

#endif

int
exist_player(string pl_name)
{
    object ob;
    int ret;

    if (!pl_name)
	return 0;
    
    seteuid(get_root_uid());
    return file_size("/players/" + extract(pl_name, 0, 0) +
		     "/" + pl_name + ".o") >= 0;
}


/*
 * Function name:   finger_player
 * Description:     Returns a player object restored with the values from
 *		    the players save file.
 * Arguments:	    pl_name: Name of player
 *		    file: (optional) Name of player_file
 * Returns:         The restored player object or 
 */
varargs object
finger_player(string pl_name, string file)
{
    object ob;
    int ret, lev;

    if (strlen(pl_name) == 0)
	return 0;

    seteuid(get_bb_uid());

    if (!file)
      {
	file = DEFAULT_PLAYER;
        if (!global_ob)
          global_ob = clone_object(file);
	ob = global_ob;
      }
    else
      {
	if (global_ob_2)
	  destruct(global_ob_2);
	global_ob_2 = clone_object(file);
	ob = global_ob_2;
      }
    
    ob->open_player();
    
#ifdef FINGER_LOG
    write_file(FINGER_LOG,SHTIME + "Finger_player called by "+file_name(this_player())+
	       " or\n    "+file_name(previous_object())+" and "+
	       file_name(ob)+" is used, command: "+query_verb()+"\n");
#endif
    
    if (function_exists("load_player", ob) !=  "/std/player_sec")
    {
	destruct(ob);
	return 0;
    }

    ob->master_set_name(pl_name);
    seteuid(get_root_uid());
    export_uid(ob);
    ret = (int) ob->load_player(pl_name);

    seteuid(get_bb_uid());
    export_uid(ob);			/* Make the object powerless */
    ob->set_trusted(1);
    seteuid(get_root_uid());
    ob->set_adj(0);		     /* Set the adjectives correctly */

    lev = query_wiz_level(pl_name);
    if (lev)
	ob->set_wiz_level(lev);

    if (ret)
    {
	return ob;
    }
    else
    {
	destruct(ob); 
	return 0;
    }
}

static void note_something(string str, string type)
{
    string cr, file;

    cr = creator_object(environment(this_player()));
    file = query_wiz_path(cr) + "/log";
    if (!file)
	return;

    seteuid(get_root_uid());

    if (file_size(file) != -2) 
	mkdir(file);

    write_file(file + type, extract(ctime(time()), 4, 9) + " " +
		file_name(environment(this_player())) +
	       " (" + capitalize((string) this_player()->query_real_name()) +
	       ")\n" + str + "\n");
}

/*
 * Function name:   query_snoop
 * Description:     Tells caller if a user is snooped.
 * Arguments:	    snoopee: pointer to a user object
 * Returns:         0 if not snooped, 1 if snooped and caller is lord or lower
 *                  object pointer to snooper if caller is arch or higher
 */
mixed
query_snoop(object snoopee)
{
    if (GETTYPE >= WIZ_ARCH)
	return efun::query_snoop(snoopee);
    else
	return (valid_snoop(previous_object(), snoopee) &&
		efun::query_snoop(snoopee));
}

/*
 * Function name:   query_start_time
 * Description:     Return the time when the game started.
 */
public int
query_start_time()
{
    return file_time("/GAME_START");
}

void note_bug(string str) { note_something(str,"/bugs"); }
void note_typo(string str) { note_something(str,"/typos"); }
void note_idea(string str) { note_something(str,"/ideas"); }
void note_praise(string str) { note_something(str,"/praise"); }

/*
 * Description: Logs a commune from a mortal
 */
commune_log(str)
{
    log_file("COMMUNE",ctime(time()) + ", " +
	     capitalize(this_interactive()->query_real_name()) + 
	     ": " + str + "\n");
}

/*
 * Function name:   master_shutdown
 * Description:     Perform a shutdown if some conditions are met.
 * Returns:	    1 - Ok, 0 - No shutdown performed.
 */
int
master_shutdown(string reason)
{
    string shutter;

    shutter = geteuid(previous_object());

    if (MASTER_OB(previous_object()) != "/cmd/wiz_cmd_normal" &&
	MASTER_OB(previous_object()) != ARMAGEDDON &&
	(query_wiz_level(shutter) < WIZ_NORMAL || !strlen(reason)))
	return 0;

#ifdef LOG_SHUTDOWN
    log_file("SHUTDOWN", ctime(time()) + " Game shutdown by " + shutter + " (" + reason + ")\n");
#endif
    
    /* This MUST be a this_object()->
       If it is removed the game wont go down, so hands off!
    */
    this_object()->do_debug("shutdown");
    return 1;
}

/*
 * Function name:  wiz_home
 * Description:    Gives a default 'home' for a wizard, domain or a player
 * Arguments:      wiz: The wizard name.
 * Returns:        A filename for the 'home' room.
 */
string
wiz_home(string wiz)
{
    string path;

    if (WIZ_TYPE(query_wiz_level(wiz)) == WIZ_MORTAL)
	if (query_domain_number(wiz) < 0)	/* Not even a domain */
	    return "";

    path = query_wiz_path(wiz) + "/workroom.c";
    seteuid(get_root_uid());
    if (file_size(path) <= 0)
	write_file(path, "inherit \"/std/workroom\";\n\ncreate_workroom()\n{\n  ::create_workroom();\n}\n");

    return path;
}

/*
 * Function name:  wiz_force_check
 * Description:    Checks if one wizard is allowed to force another
 * Arguments:      forcer: Name of wizard trying to force
 *		   forced: Name of wizard being forced
 * Returns:        True if ok
 */
int
wiz_force_check(string forcer, string forced)
{
    int             rlev,
                    dlev;
    if (forcer == forced)
	return 1;

    rlev = query_wiz_level(forcer);
    if ((rlev == WIZLEV_KEEPER) || (forcer == get_root_uid()))
	return 1;

    dlev = query_wiz_level(forced);

    if ((rlev > WIZLEV_LORD) && (dlev <= WIZLEV_LORD))
	return 1;
}

/*
 * Function name: set_sanctioned
 * Description:   Set the 'sanctioned' field in the player.
 * Arguments:     wizname - The wizard to set in
 *		  arr - The 'sanctioned' array to set.
 */
public int
set_sanctioned(string wizname, mixed *arr)
{
    string wname;
    object wiz;

    wname = geteuid(previous_object());

    if (wname != wizname &&
	WIZ_TYPE(query_wiz_level(wname)) < WIZ_ARCH)
	return 0;

    wiz = find_player(wizname);
    if (!wiz)
	return 0;

    wiz->set_sanctioned(arr);
    return 1;
}

/*
 * Function name: banish
 * Description:   Banish a name, info about name, remove a banishment.
 * Arguments:     name - the name to perform banish operation on.
 *		  what - what to do.
 * Returns:       A list with information.
 */
mixed *
banish(string name, int what)
{
    string file;
    mixed *info;

    info = allocate(2);
    
    if (function_exists("get_soul_id", previous_object()) !=  
	 "/cmd/wiz_cmd_normal")
	return ({});

    file = "/syslog/banish/" + extract(name, 0, 0) + "/" + name;
    
    if (file_size(file) > -1)
    {
	info[0] = read_file(file);
	info[1] = file_time(file);
    }

    switch (what)
    {
    case 0: /* Information */
	if (file_size(file) > -1)
	    return info;
	break;

    case 1: /* Remove */
	if (file_size(file) > -1)
	{
	    rm(file);
	    return info;
	}
	break;

    case 2: /* Add */
	if (file_size(file) > -1)
	    return info;
	write_file(file, geteuid(previous_object()));
	break;

    default: /* Strange */
	break;
    }

    return ({});
}

#define DEBUG_RESTRICTED ({ "mudstatus", "swap", "shutdown", "function_map", "send_udp" })
/*
 * Function name:  do_debug
 * Description:    Does a lot of debug things
 * Arguments:      icmd: Command
 * Returns:        information relevant to given command
 */
varargs mixed
do_debug(string icmd, mixed a1, mixed a2, mixed a3)
{
    if (member_array(icmd, DEBUG_RESTRICTED) >= 0)
    {
	if (geteuid(previous_object()) != get_root_uid() &&
	    previous_object() != this_object() &&
	    previous_object() != find_object("/secure/simul_efun"))
	    return 0;
    }
    return debug(icmd, a1, a2, a3);
}

/*
 * Function name:  do_funmap
 * Description:    Functionmaps objects. Using certain criteria for deciding
 *		   if this is legal.
 * Arguments:      ob: Object to function map
 * Returns:        True if mapped
 */
int
do_funmap(object ob)
{
    if (this_interactive() && 
	this_interactive()->query_wiz_level() > WIZLEV_LORD)
	return debug("function_map", 1, ob);

    if (previous_object() == find_object(WIZ_CMD_ARCH))
	return debug("function_map", 1, ob);

    if (LOGIN_NEW_PLAYER->legal_player(ob))
	return debug("function_map", 1, ob);
    
    return do_debug("function_map", 1, ob);
}

/*
 * Function name:  is_funmap
 * Description:    Checks if an object is functionmapped.
 * Arguments:      ob: Object to check
 * Returns:        True if mapped
 */
int
is_funmap(object ob)
{
    return debug("function_map", 0, ob);
}

#ifdef UDP_MANAGER
/*
 * Function name:   send_udp_message
 * Description:     Sends a udp message to arbitrary host, port
 * Arguments:	    to_host: Hostname or IP-number
 *		    to_port: Portnumber
 *		    msg:     Message to send
 * Returns:	    True if the message is sent. There is of course no
 *		    guarantee it will be received.
 */
int
send_udp_message(string to_host, int to_port, string msg)
{
    if (previous_object() == find_object(UDP_MANAGER))
	return debug("send_udp", to_host, to_port, msg);
    else
	return 0;
}

#endif

/*
 * Function name:  check_memory
 * Description:    Checks with 'debug malloc' if it is time to reboot
 * Arguments:      None,
 *		   The limit can be defined in config.h as MEMORY_LIMIT
 */
public void
check_memory()
{
    int mlim, d, cval, day, mon, h, m, s, date;
    string mc, bef, aft;

#ifdef MEMORY_LIMIT
    mlim = MEMORY_LIMIT;
#else
    mlim = 35000000;
#endif
    mc = debug("malloc");
    sscanf(mc, "%ssbrk requests: %d %d (a) %s", bef, d, cval, aft);
    call_out("check_memory", 15 * 30);

    if ((time() - query_start_time()) > 3600)
    {
        sscanf(ctime(time()), "%s %s %d %d:%d:%d %d", day, mon,date, h,m,s);
        if (h == REGULAR_REBOOT)
        {
            seteuid(get_root_uid());
            ARMAGEDDON->shut_for_reason("Regular Reboot time!", 20);
        }

    }
    if (cval < mlim)
	return;
    memory_failure();

    /* We should add a decay here for the xp stored for each domain
       we should also save the master object here
    */
    this_object()->decay_exp();
    seteuid(get_root_uid());
    save_object(SAVEFILE);
}
    

/*
 * Function name:  startup_udp
 * Description:    Give the contents of the package to send as startup
 *		   message to the mudlist server. This is default if we
 *		   have no UDP_MANAGER.
 * Returns:        The message.
 */
string 
startup_udp()
{
    return 
	"||NAME:" + this_object()->get_mud_name() +
	"||VERSION:" + do_debug("version") +
	"||MUDLIB:" + MUDLIB_VERSION +
	"||HOST:" + query_host_name() +
	"||PORT:" + debug("mud_port") +
	"||PORTUDP:" + debug("udp_port") +
	"||TIME:" + ctime(time());
}

/*
 * Function name:  set_known_muds
 * Description:    The UDP manager can set what muds are known.
 * Returns:	   True if set.
 */
int
set_known_muds(mapping m)
{
#ifdef UDP_MANAGER    
    if (previous_object() == find_object(UDP_MANAGER))
    {
	known_muds = m;
	return 1;
    }
#endif
    return 0;
}

/*
 * Function name:  query_known_muds
 * Description:    Give the currently known muds
 * Returns:        A mapping of information indexed with mudnames
 */
mapping
query_known_muds()
{
    if (mappingp(known_muds))
	return known_muds + ([]);
    else
	return 0;
}


/********** ADDED BY DIMITRI (AS QUIS TOLD ME) ON 07/01/93 *************/

/*
 * Function name:   linkdead_player
 * Description:     Called from GD if a player goes linkdead
 * Arguments:          ob:         The player that went linkdead
 */

void
linkdead_player(object ob)
{
#ifdef STATUE_WHEN_LINKDEAD
   ob->set_linkdead(1);
#    ifdef OWN_STATUE
   OWN_STATUE->die(ob);
#    else   
   say("Suddenly " + QTNAME(ob) + " moans and turns into stone.\n");
#    endif  
#endif
}



/* added by sardane (get backbone for house_master.c) */

load_house_master()
{
    "/local/std/house/house_master"->hand_load();
    return;
}    

/*
 * Function name:  
 * Description:    
 * Arguments:      
 * Returns:        
 */
