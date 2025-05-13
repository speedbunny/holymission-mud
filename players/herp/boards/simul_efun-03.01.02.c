/*
 * This is a mudlib file. Copy it to /obj/simul_efun.c, or
 * wherever the get_simul_efun() in master.c says.
 * The functions defined in this file should only be replacements of efuns
 * no longer supported. Don't use these functions any longer, use the
 * replacement instead.
 */

/*
  simul_efun.c

  This is the efuns to be that we have to simulate until they exist in the
  Game Driver.

*/

#include "/secure/std.h"

#pragma strict_types
#pragma save_types

/*
 * The ls() function is no longer needed, as get_dir() can do the same
 * work.
 */
void ls(string path) {
    int max, i, len, tmp;
    status trunc_flag;
    string *dir;
#ifndef COMPAT_FLAG
    seteuid(geteuid(previous_object()));
#endif
    dir = get_dir (path);
#if defined(COMPAT_FLAG)
    if (path[0] == '/')
	path = extract(path, 1);
    if (path != "")
	path += "/";
#else
    if (path != "/")
	path += "/";
#endif
    if (!dir) {
        write("No such directory.\n");
        return;
    }
    if (sizeof(dir) > 999)
    {
        dir = dir[0..998];
        trunc_flag = 1;
    }
    max = (int)("/obj/master"->test_dir(dir,path));
    if (max > 79)
        max = 79;
    for (i=0; i < sizeof(dir); i++) {
	string name;
            name = dir[i];
	tmp = strlen(name);
	if (len + tmp > 79) {
	    len = 0;
	    write("\n");
	}
	write(name);
        if (len + max > 79) {
            write("\n");
            len = 0;
        } else {
            write(extract(
"                                                                                ",
                80-max+tmp));
            len += max;
        }
    }
    write("\n");
    if (trunc_flag) write("***TRUNCATED***\n");
}

/*
 * Function name: exclude_array
 * Description:   Deletes a section of an array
 * Arguments:     arr: The array
 *		  from: Index from which to delete elements
 *		  to: Last index to be deleted.
 * Returns:       
 */
public mixed *
exclude_array(mixed *arr, int from, int to)
{
    return arr[0..from-1] + arr[to+1..sizeof(arr)];
}

/*
 * Function name: exclude_element
 * Description:   deletes an element from an array
 * Arguments:     arr: the array
 *                from: index of the element to remove from the array
 * Returns:       first element of the array, or -1 if failed.
 * Warning:       elements in the array will have been reshuffled somewhat.
 */
public mixed * exclude_element (mixed *arr, int index) {
        arr[index] = arr[0];
        return arr[1..sizeof (arr)];
}


/*************************************************************************/

/* Efun: all_environment() */

/*
 * Function name: all_environment
 * Description:   Gives an array of all containers which an object is in, i.e.
 *		  match in matchbox in bigbox in chest in room, would for the
 *		  match give: matchbox, bigbox, chest, room 
 * Arguments:     ob: The object
 * Returns:       The array of containers.
 */
public object *
all_environment(object ob)
{
  object *r;
  
  if (!ob || !environment(ob)) return 0;
  if (!environment(environment(ob)))
      return ({ environment(ob) });
  r = ({ ob = environment(ob) });
  while (environment(ob))
      r = r + ({ ob = environment(ob) });
  return r;
}

/* this_interavtive - in 3.0.53 replaced by this_player(1) */
object this_interactive () { return this_player (1); }

/*************************************************************************/

/* Efuns: break_string() and update_actions()
*/

static int gCol;

/*
 * Function name: break_string
 * Description:   Breaks a continous string without newlines into a string
 *		  with newlines inserted at regular intervalls replacing spaces
 *		  Each newline separeted string can be indented with a given
 *		  number of spaces.
 * Arguments:     str: Original message
 *		  width: The total maximum width of each line.
 *		  indent: (optional) How many spaces to indent with.
 * Returns:       A string with newline separated strings
 */
public varargs string
break_string(string str, int width, int indent)
{
    mixed *brkarg;
    string indstr;

    if (indent)
	indstr = extract("                                                                                ", 0, indent-1);
    else
	indstr = "";
    gCol = indent;
    brkarg = ({ width, indstr });
  
    return indstr + 
	implode(map_array(explode(str+" "," "),"brk",this_object(),brkarg)," ");
}

static string brk(string word, mixed *width_indstr)
{
    int width;
    string indstr;

    width = width_indstr[0];
    indstr = width_indstr[1];
    if ((strlen(word)+gCol) > width) {
	gCol = strlen(indstr) + strlen(word) + 1;
	return "\n" + indstr + word;
    }
    else {
	gCol += strlen(word) + 1;
	return word;
    }
}    

/*
 * Function name:   update_actions
 * Description:     Updates this_objects actions in all living objects
 */
public void
update_actions()
{
  int objs;

  if (environment(previous_object()))
    previous_object()->move(environment(previous_object()),1);
  filter_array(all_inventory(previous_object()),"move_inv",previous_object());
}

static void move_inv(object ob) { if (living(ob)) ob->move(previous_object(),1); }

/*************************************************************************/


/* Functions below are useful but should probably not be made into efuns
*/

string creator(object ob) { return (string)SECURITY->creator_object(ob); }
string domain(object ob) { return (string)SECURITY->domain_object(ob); }


static void dump_elem(mixed sak, string tab);

/*
 * Function name: dump_array
 * Description:   Dumps a variable with write() for debugging purposes.
 * Arguments:     a: Anything including an array
 */
public varargs void 
dump_array(mixed *a, string tab)
{
  int n,m;

  if (!tab) tab = "";
  if (!pointerp(a)) {
    write(a); return;
  }
  else write("\n");
  m=sizeof(a);
  n=0;
  while (n<m) {
    write(tab+"["+n+"] = "); dump_elem(a[n],tab); n+=1;
  }
}

static void dump_elem(mixed sak, string tab)
{
  if (pointerp(sak)) {
    write("Array: \n"); dump_array(sak,tab+"   ");
  }
  else write(sak);
  write("\n");
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
