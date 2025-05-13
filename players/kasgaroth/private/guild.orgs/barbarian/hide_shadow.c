/* 930723 mud@mud.edvz.uni-linz.ac.at Herp aka Herbert Rosmanith */

/*------------------------------------------------------------------*
 * A thief can hide things, and reveal them later.                  *
 * Technically, that is done by shadowing id() and short()          *
 * The new id() function will append a special string to the        *
 * original id, so it will still be possible to identify            *
 * hidden item.                                                     *
 * NOTE: when an object is hidden using the identfier "A", the only *
 *       possibility to identify it again is "A", even though it    *
 *       may have multiple id()'s originally.                       *
 * The actions "hide" and "reveal" are processed in the thief-soul. *
 *------------------------------------------------------------------*/

#define TP      this_player()
#define Str     0
#define Dex     1
#define Con     2
#define Int     3
#define Wis     4
#define Chr     5

object target;                   /* Whom we are shadowing */
string sid;			 /* special id */

start_shadow(object ob,string id) {
    target=ob;
    sid=id+"__hidden__";
    shadow(ob,1);
}

/* these are the overwritten functions: id() and short() */

id(string str) {
    return str==sid;
}

short() {
    return 0;
}
