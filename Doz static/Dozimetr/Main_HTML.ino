void HTTP_Main(){
  String cssClass = "mediumhot";
  String message="";
message += "<!DOCTYPE html>";
message += "<html>";
message +=     "<head>";
message +=         "<meta name=\"viewport\" content=\"width=device-width\" charset=\"utf-8\">";
message +=         "<meta http-equiv=\"Refresh\" content=\""+ String(Config.EXPOSITION * 60 + 1)+ "\" />";
message +=         "<title>Dosimetr</title>";
message +=         "<link href=\"https://fonts.googleapis.com/css?family=Advent+Pro\" rel=\"stylesheet\" type=\"text/css\">";
message +=         "<style type=\"text/css\">";
message +=             "html {height: 100%; }";
message +=             ".data {color: #fff;font-family: Advent Pro ;font-weight: 400; text-align: center;}";
message +=             "h1 {text-align: center;}";
message +=             "h2 {text-align: center; font-size: 90px;font-weight: 400; margin: 0}";
message +=             "table { position: absolute; z-index: 0; top: 50%; left: 50%; margin-right: -50%; transform: translate(-50%, -50%)}";
message +=             "td{ display: inline-block; width:400px;}";
message +=             "body {margin: 0;}";
message +=             ".knopki{position: relative; z-index: 1; text-align: center; height: 35px; width: 100px;}";
message +=             ".cold       {background: linear-gradient(to bottom, #7abcff,#0665e0);}";
message +=             ".mediumhot  {background: linear-gradient(to bottom, #81ef85,#057003);}";
message +=             ".hot        {background: linear-gradient(to bottom, #fcdb88,#d32106);}";
      
message +=       "@media screen and (max-width:1500px) { td{width:40%;} table{left: 62%; margin-right: -62%;}}";
message +=       "@media screen and (max-width:800px) { td{width:40%; margin:20px;} table{left: 55%; margin-right: -55%;} h1{font-size: 30px;} h2{font-size: 40px;}}";
message +=       "@media screen and (max-width:640px) { td{width:30%; margin:20px;} table{left: 60%; margin-right: -60%;} h1{font-size: 30px;} h2{font-size: 30px;}}";
message +=       "@media screen and (max-width:560px) { td{width:50%; margin:18px;} table{left: 80%; margin-right: -80%;} h1{font-size: 25px;} h2{font-size: 25px;}}";
message +=       "@media screen and (max-width:400px) { td{width:50%; margin:10px;} table{left: 80%; margin-right: -80%; top: 40%;} h1{font-size: 20px;} h2{font-size: 20px;}}";
          
message +=         "</style>";
message +=     "</head>";
    
message += "<body class=\""+cssClass+"\">";
message +=     "<div>";
message +=          "<form action=\"/settings_WiFi_AP\"><button class=\"knopki\" type=\"submit\">WI-FI<br>AP</button></form>";
message +=          "<br><form action=\"/settings_exposition\"><button class=\"knopki\" type=\"submit\">EXPOSITION<br>NARODMON</button></form>";

message +=     "</div>";
message +=     "<div class=\"data\">";
message +=         "<table cellspacing=\"100\">";
message +=             "<tr><td><h1>Dose rate</h1><h2>"+String(temp)+"&nbsp;<small>mkR/h</small></h2></td></tr>";
message +=         "</table>";
message +=     "</div>";
message += "</body>";
message += "</html>";


    server.send(200, "text/html", message);

  
}
