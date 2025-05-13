// File: /obj/base.c					Author: Sauron
//							Date:	120597

// Purpose:
// This file contains code basic to all lib inheritable objects. Talk to
// an Arch if you want anything adding here.


// Global variables:

mapping save_props;
static mapping static_props;

// End global variables.

// Prototypes:

nomask private static void init_properties();
varargs int add_property(string prop,mixed val,int save);
int remove_property(string prop);
nomask varargs mixed query_property(string prop,int save);
nomask string *property_list();
void reset(int arg);
void init();

// End prototypes.

/* USERDOC:
init_properties
Format  : init_properties()
See also: add_property, remove_property, query_property, property_list.

Initialises the savable and static property mappings.
*/

nomask private static void init_properties() {
  if(!save_props)
    save_props=([]);
  if(!static_props)
    static_props=([]);
}

/* USERDOC:
add_property
Format  : i=add_property(s,m,i)
See also: remove_property, query_property, property_list.

This function adds the given property s to the object's property list with
the value v. If the extra argument i is given, and is non-zero, the
property will be restored/saved. It returns 1 for success, or 0 if either
the property or it's value was invalid. 
*/

varargs int add_property(string prop,mixed val,int save) {
  if(!save_props || !static_props)
    init_properties();

  if(!prop || !val)  
    return 0;

  else if(save) {
    save_props[prop]=val;
    return 1;
  }
  else {
    static_props[prop]=val;
    return 1;
  }
}

/* USERDOC:
remove_property
Format  : i=remove_property(s)  
See also: add_property, query_property, property_list.

This function removes the given property s from the object's property
list. It returns 1 for success, or 0 if the property wasn't set in the
first place.
*/

int remove_property(string prop) {
  if(!save_props || !static_props)
    init_properties();

  if(!prop || !query_property(prop))
    return 0;
  else {
    if(save_props[prop])
      save_props=m_delete(save_props,prop);
    if(static_props[prop])
      static_props=m_delete(static_props,prop);
    return 1;
  }
}

/* USERDOC:
query_property
Format  : m=query_property(s)
See also: add_property, remove_property, property_list.

This function queries the value of the given property s in the object's
property list. It returns the value if found, or 0 if the property wasn't
set in the first place.
*/

nomask varargs mixed query_property(string prop,int save) {
  if(!save_props || !static_props)
    init_properties();

  if(!prop) {
    if(save)
      return save_props;
    else
      return static_props;
  }
  else if(save_props[prop])
    return save_props[prop];
  else if(static_props[prop])
    return static_props[prop];
  else
    return 0;
}

/* USERDOC:
property_list
Format  : s*=property_list()
See also: add_property, remove_property, query_property.

This function returns a list of all the properties set in the object. It
does not return the values set.
*/

nomask string *property_list() {
  if(!save_props || !static_props)
    init_properties();

  return ({"save_props:"})+m_indices(save_props)+
         ({"static_props:"})+m_indices(static_props);
}

// These two functions are here so that this object's 'children' can
// automatically use ::reset(arg) and ::init(). This means that if we ever
// need to add anything to the reset or init of the base object, we can do
// so without having to add these lines to this object's 'children' at
// a later date.

void reset(int arg) {
  if(!arg) {
    init_properties();
  }
}

void init() {
}
