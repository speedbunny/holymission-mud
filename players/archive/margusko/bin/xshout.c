   int cmd_xshout(string str) {
         if( !str ) {
               notify_fail("OOOpppps !");
               return 0;
         }
         shout(sprintf("Margusko moos loudly: %s\n",str));
         return 1;
}
