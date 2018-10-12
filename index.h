const char MAIN_page[] PROGMEM = R"=====(
<html lang="en">
<head>
  <meta charset="utf-8">
</head><body>
  <div class="container">
    <div class="row"><h1>Theo dõi nhiệt độ và độ ẩm</h1></div>
    <div class="row">
      <div class="colum2">Nhiệt độ</div>
      <div class="colum2">Độ ẩm</div>
    </div>
    <div class="row">
      <div class="colum2" id="nhietdo">25</div>
      <div class="colum2" id="doam">77</div>
    </div>
    <div class="clear"></div>
</div>
  <style>
    .container {
    width: 50%;
    height: max-content;
    background: lightgreen;
    color: white;
    margin: auto;
    padding: 10px;
}

h1 {
    text-align: center;
    padding-bottom: 20px;
    margin: 0;
}

.colum1 {
    width: 100%;
    text-align: center;
}

.colum2 {
    width: 50%;
    display: inline-block;
}
.row {
    width: 100%;
    height: auto;
}
.row .colum2 {
    width: 50%;
    float: left;
    text-align: center;
    font-size: 20px;
}
div.col3 {
    float: left;
    width: 50%;
    text-align: center;
    font-size: 20px;
}
.clear {
    clear: both;
}
  </style>
  <script>
    function getData() {
  var xhttp = new XMLHttpRequest(); 
  xhttp.onreadystatechange = function() {
    if (this.readyState == 4 && this.status == 200) {
      document.getElementById("nhietdo").innerHTML =
      this.responseText; // Nhan ket qua tu server
    }
  };
  xhttp.open("GET", "temp", true); // Tao yeu cau tu client
  xhttp.send(); // Gui yeu cau cua client len Server
}

function getDoAm() {
  var xhttp = new XMLHttpRequest();
  xhttp.onreadystatechange = function() {
    if (this.readyState == 4 && this.status == 200) {
      document.getElementById("doam").innerHTML =
      this.responseText;
    }
  };
  xhttp.open("GET", "humi", true);
  xhttp.send();
}

// Hàm thực hiện gửi yêu cầu của client cứ 1s gửi 1 lần
setInterval(function() {
  getData();
  getDoAm();
}, 1000);

  </script>


</body></html>
)=====";
