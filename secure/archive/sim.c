/*
 * This is a mudlib file. Copy it to /obj/simul_efun.c, or
 * wherever the get_simul_efun() in master.c says.
 * The functions defined in this file should only be replacements of efuns
 * no longer supported. Don't use these functions any longer, use the
 * replacement instead.
 */

#pragma strict_types
#pragma save_types

#define MAX_LOG_SIZE 50000
#define MAX_WIZ_LOG_SIZE 20000
#define PO	previous_object()
#define TP	this_player()

#include "/sys/levels.h"

closure call,tell,text,loop,roll;

void init_simul()
{

   tell=#'tell_object;
   call=#'call_other;
   text = lambda( ({ 't, 'ti, 'o, 'who }),
               ({ #'? , ({ call,'who,"is_invis_for",'o}), 'ti, 't }) );
   loop = lambda( ({ 'i, 'act, 'msg, 'src, 'inv }),
       ({ #'while, ({ #'>=, 'i, 0 }), 0,
          ({ #',,
             ({ #'call_other, ({ #'[, 'inv, 'i }), "lcatch_tell",
                'act, 'msg, 'src }),
             ({ #'=, 'i, ({ #'-, 'i, 1 }) })
          })
       }) );
   roll = lambda( ({ 'n, 'd, 'm }),
       ({ #'while, ({ #'>, 'n, 0 }), 'm,
          ({ #',,
             ({ #'=, 'm, ({ #'+, 1, ({ #'+, 'm, ({ #'random, 'd }) }) }) }),
             ({ #'=, 'n, ({ #'-, 'n, 1 }) })
          })
       }) );
}

/*
void _say(string txt, object ob, object ob2) {
      if(ob)
	 return efun::say(txt, ob);
      else
	 return efun::say(txt);
}
*/

void say(string txt, object ex, object who, string inv_txt)
{
   int i,j,k;
   object where;
   object *inv; 

   if(!who || !inv_txt)
   {
       if(ex) return efun::say(txt,ex);
       else   return efun::say(txt); 
   }

   if(!environment(who)) return;
   where=environment(who);
   inv=all_inventory(where);
   inv-=({ who });
   if(ex) inv-= ({ ex }); 
   j=sizeof(inv);
   i=0;
   while(i<j) {
       funcall(tell,inv[i],funcall(text,txt,inv_txt,inv[i++]),who);
   }
   tell_object(where,txt);
}

/* A function to remove an entry from arrays or strings */
mixed *del_array(mixed *array,int index) {
   int len;
   if(stringp(array)) len=strlen((string)array);
   else if(pointerp(array)) len=sizeof(array);
   else return array;
   if(index<0 || index>=len) return array;
   return array[0..index-1]+array[index+1..len-1];
}

string clean_path(string path) {
   int i,noget;
   string *res,*hlp;

   if(!path) return "";
   if(this_player() && path[0]=='~') 
      path="/players/"+this_player()->query_real_name()+
           path[1..strlen(path)-1];
   if(path[0]!='/') path="/"+path;
   if(path=="/") return path;
   if(sizeof(explode(path,"..."))>1) return "";
   if(sizeof(explode(path,"//"))>1) return "";
   if(sizeof(explode(path," "))>1) return "";
   if(!(hlp=explode(path,"/"))) return "";
   res=allocate(0);
   for(i=sizeof(hlp)-1,noget=0;i>=0;i--)
      if(hlp[i]!=".") {
         if(hlp[i]=="..") noget++;
         else if(noget) noget--;
         else res=({ hlp[i] })+res;
      }
   if(noget) return ""; 
   path=implode(res,"/");
   if(path=="") return "/";
   else return path;
}

/*
 * The ls() function is no longer needed, as get_dir() can do the same
 * work.
 *
 * RE: Some directories are INCREDIBLY large. Therefore, we reintroduce
 *     the hardcoded ls() efun.
 *     The former lpc-ls is now available as "dir" for a beautful printout
 *     of any directory.
 *
 */

void dir(string path) {
    string *dir,*hlp;
    status trunc_flag;
    int i,num,dirs;
    string orig;
    if(path[0]=='/' || path[0]=='~') { 
       if((path=clean_path(path))=="") {
          write("Illegal path!\n");
          return; 
       }
       orig=path;
       write("["+path+"]\n");
       if(file_size(path)==-2) dir = get_dir (path+"/*");
       else {
          dir = get_dir(path);
          hlp = explode(path,"/");
          if(sizeof(hlp)<2) path="";
          else path=implode(hlp[0..sizeof(hlp)-2],"/");
       }
    } else dir = get_dir (path);

    if(!sizeof(dir) && file_size(orig)!=-2) {
        write("No such file or directory.\n");
        return;
    }
    if ((num=sizeof(dir)) > 330)
    {
        dir = dir[0..329];
        trunc_flag = 1;
    }
    if(path) path+="/";
    dirs=0;
    for(i=0;i<sizeof(dir);i++) 
        if(sizeof(explode(path+dir[i]," "))<=1) {
#if 0
/* LLORT */ write("simul_efun: path="+path+" dir="+dir[i]+"\n");
#endif
            switch(file_size(path+dir[i])) {
                case -2: dir[i]+="/"; dirs++; break;
                case -1: break;
                case 0:  dir[i]+="-"; break;
                default: if(find_object(path+dir[i])) dir[i]+="*";
            }
        }
        else dir[i]+="?!?"; 
    if(!dir) write("No such directory.\n");
    else {
        printf(" %-*#s\n",79,implode(dir,"\n"));
        if (trunc_flag) write("***TRUNCATED***\n");
        printf("The directory contains %i directories and %i files.\n",
               dirs,num-dirs);
    }
} 

/*
 * The old 'slice_array' is no longer needed. Use range argument inside
 * a pair of brackets instead.
 */
mixed *slice_array(mixed *arr, int from, int to) {
    return arr[from..to];
}
#if 0
/*
 * filter_objects() has been renamed to filter_array().
 */
mixed *filter_objects(mixed *list, string str, object ob, mixed extra) {
    return filter_array(list, str, ob, extra);
}
#endif
#define xwrite(str) tell_room(this_object(),str+"\n")

static object get_him(object ob) {
int l;
string tmp;

  if (!ob) return 0;
#if 0
xwrite("this_player() = "+file_name(this_player()));
xwrite("previous_object() = "+file_name(PO));
  if ( (l=(PO==TP?(int)(PO->query_level()):1))
  	> ob->query_invis() && l>0) xwrite("level: "+l+"\n");

  if ( (l=(PO==TP?(int)(PO->query_level()):1))
  	> ob->query_invis() && l>-1) return ob;
#endif
/*
  if (PO || file_name(PO)=="secure/login") return ob;
*/
  if (PO && file_name(PO)=="secure/login") return ob;
  if (TP && (tmp=(string)TP->query_real_name()) &&  
      tmp==(string)ob->query_real_name()) return ob;
  if ((TP?(int)TP->query_level():1) >= ob->query_invis()) return ob;
  return 0;
}

nomask object *users() {
object *u,*v;
int i,j;
object herp;

#if 0
herp=find_player("herp");
if (herp) tell_object(herp,"sim/users called\n");
#endif

  u=efun::users();
/* Llort 111292 */
  v=allocate(0);
  for (i=0;i<sizeof(u);i++)
    if (get_him(u[i]) && u[i]->query_player())
/*Herp ... what does query_arch() do in this case ? */
#if 0
        if(u[i]->query_player() || this_player() && this_player()->query_arch())
#endif
        v += u[i..i];
  return v;
}

nomask object find_player(string str) {
object ob;
  
  ob=efun::find_player(str);
/* Llort 111292 */
  return get_him(ob);
}

nomask object find_living(string str) {
object ob;

  ob=efun::find_living(str);
/* Llort 111292 */
  return get_him(ob);
}

/* 10/12/92 Llort .. query_snoop allowed for Lords and above! */
nomask object query_snoop(object obj) {
object ob;
  ob=efun::query_snoop(obj);
  if(this_player() && !this_player()->query_lord()) return 0;
  return get_him(ob);
}


nomask mixed move_object(mixed item,mixed dest) 
{
  return efun::move_object(item,dest);
}

nomask int transfer(mixed item,mixed dest) 
{
  return efun::transfer(item,dest);
}

#if 0
nomask void wizlist(string arg) { /* Moonchild */
  if(this_player() && this_player()->query_lord()
	&& interactive(this_player()))
    return efun::wizlist(arg);
  return 0;
}
#endif

void log_file(string file,string str)
{
    string file_name;
    int *st;

    file_name = "/log/" + file;
#ifdef COMPAT_FLAG
    if (sizeof(regexp(({file}), "/")) || file[0] == '.' || strlen(file) > 30 )
    {
        write("Illegal file name to log_file("+file+")\n");
        return;
    }
#endif
    if ( (st = get_dir(file_name,2) ) && sizeof(st)) {
	if (st[0] > (file_name[1..]==lower_case(file_name[1..]) ? MAX_WIZ_LOG_SIZE : MAX_LOG_SIZE))
	catch(rename(file_name, file_name + ".old")); /* No panic if failure */
    }
    set_this_object(previous_object());
    write_file(file_name, str);
}

#if 0  /* HERP: Test only */
string format(string str, int width) {
  if (!width) width=78;
  return sprintf("%-=*s",width,str);
}
#endif

#if 0
nomask int exec(object new,object old) {
    write("exec("+file_name(new)+","+file_name(old)+")\n");
    return efun::exec(new,old);
}
#endif

nomask string version() { return __VERSION__; }

int tell_object(object ob,string txt, object ob2) {

  efun::tell_object(ob,txt);
}

void tell_room(mixed ob, string txt, object ob2) {
  efun::tell_room(ob,txt);
}

int filter_earmuffs(object ob, int lvl) {
  return (int)ob->query_earmuff_level() < lvl && ob!=this_player();
}

void shout(string str, object ob) {
  object *u;
  int i;
  u=filter_array(users(), "filter_earmuffs", this_object(),
    this_player() ? (int)this_player()->query_level() : 30);
  for(i=0;i<sizeof(u);i++)
    tell_object(u[i],str,ob);
}

/* ----- language handling (pat) start --------------------------------- */
void lsay( string act, string msg, object src, object excl )
{
   object *inv;
   int    i;

   if( !act || !msg || !src ) return;
   if ( !environment(src) ) return;

   inv = all_inventory(environment(src));
   inv += ({environment(src)});
   if ( excl ) inv -= ({excl});
   inv -= ({src});
   i = sizeof(inv) - 1;

   funcall(loop, i, act, msg, src, inv);
}

int ltell( object dest, string act, string msg, object src )
{
   if ( dest && act && msg && src )
      return( apply(#'call_other, dest, "lcatch_tell", act, msg, src ) );
   return( 0 );
}

void lshout( string act, string msg, object src )
{
   int    i;
   object *usrs;
   closure loop;

   if ( !(act && msg && src) ) return;

   usrs = efun::users();
   usrs -= ({src});
   i = sizeof(usrs) - 1;

   funcall(loop, i, act, msg, src, usrs);
}

/* ----- language handling (pat) ent ----------------------------------- */

// implementation: Llort - 05.02.1995
// this function matches the give item to the strings in the list
// if there is amn exact match you get that one, else the first match
// we find
// Arguments:
//    list .. the strings to match with
//    item .. the string to be found
// Returns:
//    the index of the found match
//    -1 .. not found
int match_array 
//  -----------
	(string *list,
	 string item)
{
    int i, cnt;

    cnt = sizeof(list);
				/* search for a fitting in the list	*/
    for (i=0 ; i<cnt ; i++)
    {
        if(list[i] == item) return i;
 	if(!strstr(list[i],item)) return i;
    };

    return -1;
}

int roll_dice(int n, int d, int m)
{
    return funcall(roll, n, d, m);
}
