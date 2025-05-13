
 /* master_house.c      Metaprat       15th April 1992     */

 /* An object that stores an array of house information. */
 /* Its made living, so that people can locate it.       */


string table_owners;
string table_houses;
string table_times;


reset(arg) {
   if (arg) {
      return;
   }
   enable_commands();
   set_living_name("master_house_ob");
   table_owners = ({ });
   table_houses = ({ });
   table_times  = ({ });
}


query_house(owner_name) {
   int indx;

   for (indx = 0; indx < sizeof(table_owners); indx ++) {
      if (table_owners[indx] == owner_name) {
         return table_houses[indx];
      }
   }
   return 0;
}


register_house(owner_name, house_ob) {
   table_owners = table_owners + ({ owner_name });
   table_houses = table_houses + ({ house_ob });
   table_times  = table_times +  ({ ctime(time()) });
}
