#include <iostream>
#include <string>
#include <fstream>

using namespace std;

void print_code(int n, int p) {

    int i;
    cout << hex << p << ": ";
    for (i = 0; max_op; i++) {
        cout << setfill("0") << setw(5) << robot[n]^.code[p].op[i] << " ";
    }
    cout << " = ";
    for (i = 0; max_op; i++) {
        cout << hex << robot[n]^.code[p].op[i] << "h" << "\n\n";
    }

}

void check_plen(int plen) {

    if (plen>maxcode) {
        prog_error(16,#13#10+"Maximum program length exceeded, (Limit: "+ cstr(maxcode+1)+" compiled lines)");
}

void reset_software(int n) {

    int i;

//     with robot[n]^ do

       for (i; max_ram; i++ to max_ram){
             ram[i]:=0;
     }

       n.ram[71] = 768;
       n.thd = hd;
       n.tspd = 0;
       n.scanarc = 8;
       n.shift = 0;
       n.err = 0;
       n.overburn = false;
       n.keepshift = false;
       n.ip = 0;
       n.accuracy = 0;
       n.meters = 0;
       n.delay_left = 0;
       n.time_left = 0;
       n.shields_up = false;

}

void init_robot(int n) {

    int i,j,k,l;

    robot[n].wins = 0;
    robot[n].trials = 0;
    robot[n].kills = 0;
    robot[n].deaths = 0;
    robot[n].shots_fired = 0;
    robot[n].match_shots = 0;
    robot[n].hits = 0;
    robot[n].damage_total = 0;
    robot[n].cycles_lived = 0;
    robot[n].error_count = 0;
    robot[n].plen = 0;
    robot[n].max_time = 0;
    robot[n].name = '';
    robot[n].fn = '';
    robot[n].speed = 0;
    robot[n].arc_count = 0;
    robot[n].sonar_count = 0;
    robot[n].robot_time_limit = 0;
    robot[n].scanrange = 1500;
    robot[n].shotstrength = 1;
    robot[n].damageadj = 1;
    robot[n].speedadj = 1;
    robot[n].mines = 0;

    robot.config.scanner = 5;
    robot.config.weapon = 2;
    robot.config.armor = 2;
    robot.config.engine = 2;
    robot.config.heatsinks = 1;
    robot.config.shield = 0;
    robot.config.mines = 0;

    for (i = 0; i < max_ram; i++) {
        ram[i] = 0;
    }

    ram[71] = 768;

    for (i = 0; i < max_code; i++) {
        for (k = 0; k < max_op; k++) {
            code[i].op[k] = 0;
        }
    }
   reset_hardware(n);
   reset_software(n);
}





void shutdown() {

    int i,j,k;

// graph_mode(false);
    if (show_cnotice = true) {

//   textcolor(3);
    cout << progname << " " << version << " ";
    cout << cnotice1 << "\n";
    cout << cnotice2 << "\n";
    cout << cnotice3 << "\n";
  }

// textcolor(7);
    if (registered = false) {
//        textcolor(4);
        cout << "Unregistered version";
    } else {
        cout << "Registered to: " << reg_name;
    }
// textcolor(7);
    cout << "\n";
    if (logging_errors = true) {

    for (i = 0; i < num_robots; i++){
        cout << "Robot error-log created: " << robot[i].base_name(fn) << ".ERR";
        errorlog.close();
    }
   exit();
}


bool file_exists(string filename)
{
    ifstream testopen(filename);
    return testopen.good();
}

//NOT DONE
void delete_compile_report(){

//    if exist(main_filename+compile_ext) then
//       delete_file(main_filename+compile_ext);


}

void write_compile_report(){

    ofstream f;
    int i,j,k;

    f.open(main_filename+compile_ext);

    cout << f << num_robots + 1 << "\n";

    for (i = 0; i < num_robots; i++){
         cout << robot[i].f << robot[i].fn << "\n";
    }

    f.close();
// textcolor(15);

    cout << "\nAll compiles successful!" << "\n\n";

    exit();
}

int parse_param(string s) {

    ofstream f;
    string fn, s1;
    bool found;

    found = false;
    s = btrim(toupper(s));

    if (s == ""){
        exit();
    }

   if (s[1] == "#"){

       fn = ATR2FUNC::rstr(s,s.length()-1);
       if (fn == base_name(fn)){
           fn = fn + config_ext;
       }
       //   if not exist(fn) then prog_error(6,fn);
       //   assign(f,fn); reset(f);
       //   while not eof(f) do
       //     readln(f,s1);
       //     s1:=ucase(btrim(s1));
       //     if s1[1]='#' then prog_error(7,s1)
       //        else parse_param(s1);
       //    end;
       //   close(f);
       //   found:=true;
   }

    else if (s[1] == "/" || s[1] == "-" || s[1] == "="){
        s1 = ATR2FUNC::rstr(s,s.length()-1);
        if (s1[1] == "X"){
            step_mode = value(ATR2FUNC::rstr(s1,s1.length()-1));
            found = true;
            if (step_mode == 0){
                step_mode = 1;
            }
            if (step_mode < 1 || step_mode > 9){
                prog_error(24,ATR2FUNC::rstr(s1,s1.length()-1));
            }
        }

    if (s1[1] == "D"){
        game_delay = value(ATR2FUNC::rstr(s1,s1.length()-1));
        found = true;
    }

    if (s1[1] == "T"){
        time_slice = value(ATR2FUNC::rstr(s1,s1.length()-1));
        found = true;
    }

    if (s1[1] == "L"){
        game_limit = value(ATR2FUNC::rstr(s1,s1.length()-1))*1000;
        found = true;
    }

    if (s1[1] == "Q"){
        sound_on = false;
        found = true;
    }

   if (s1[1] == "M"){
       matches = value(ATR2FUNC::rstr(s1,s1.length()-1));
       found = true;
   }

   if (s1[1] == "S"){
       show_source = false;
       found = true;
   }

   if (s1[1] == "G"){
       no_gfx = true;
       found = true;
   }

   if (s1[1] == "R") {
       report = true;
       found = true;
       if (s1.length() > 1){
           report_type = value(ATR2FUNC::rstr(s1,s1.length()-1))
       }
   }

   if (s1[1] == "C"){
       compile_only = true;
       found = true;
   }

   if (s1[1] == "^"){
       show_cnotice = false;
       found = true;
   }

   if (s1[1] == "A"){
       show_arcs = true;
       found = true;
   }

   if (s1[1] == "W"){
       windoze = false;
       found = true;
   }

   if (s1[1] == "$"){
       debug_info = true;
       found = true;
   }

   if (s1[1] == "#"){
       maxcode = value(ATR2FUNC::rstr(s1,s1.length()-1))-1;
       found = true;
   }

   if (s1[1] == "!"){
       insane_missiles = true;
       if (s1.length() > 1){
           insanity = value(ATR2FUNC::rstr(s1,s1.length()-1))
       }
       found = true;
   }

   if (s1[1] == "@"){
       old_shields = true;
       found = true;
   }

   if (s1[1] == "E"){
       logging_errors = true;
       found = true;
   }

   if (insanity < 0){
       insanity = 0;
   }

   if (insanity > 15){
       insanity = 15;
   }

   else if (s[1] = ";"){
       found = true;
   }

   else if (num_robots < max_robots && s != ""){
       num_robots++;
       create_robot(num_robots,s);
       found = true;
       if (num_robots == max_robots){
           cout << "Maximum number of robots reached." << "\n";
       }
   }

   else prog_error(10,'');

   if (found != true){
       prog_error(8,s);
   }

}

















