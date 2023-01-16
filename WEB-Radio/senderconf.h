const char SENDER_page[] PROGMEM = R"=====(
<!DOCTYPE html>
<html>
  <style>
  body {
    text-align:center;
    font-family: helvetica;
  }
  </style>
  <head>
    <meta charset="utf-8" />
    <title>
      WEB-Radio Senderliste
    </title>
    <style type="text/css">

      a:link, a:visited {
        font-family: Arial, Helvetica, sans-serif;
        font-size: 20pt;
        color: #000000;
        text-decoration: none;
        margin-right: 30px; 
      }
      a:hover, a:active {
        color: #000000;
        text-decoration: underline;
      }

      p {
          //width: 20em;
          font-size: 3.0em;
      }

      .playing {
        font-family: Arial, Helvetica, sans-serif;
        font-size: 40pt;
        color: #00AA00;
        text-decoration: none;
        margin-right: 30px; 
      }

    </style>
  <head>
  <body>
    <h1>WEB-Radio</h1>
    <p>
      *feedback1*
    </p>
    <h3>Senderliste</h3>
    <form method="POST">
      <input type="submit" value="alles speichern" style="background-color:#FF5555;">
      <hr>
*fields*
      <hr>
      <input type="submit" value="alles speichern" style="background-color:#FF5555;">
      <hr>
    </form>
    <p>
      *feedback2*
    </p>
  </body>
</html>
)=====";
