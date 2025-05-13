int cmd_renew(string str) {
command("update "+str, this_player());
command("load "+str, this_player());
return 1;
}
