var pics = document.getElementsByClassName("welcome_pic");
var imgIndex = 1 //Math.floor(Math.random() * pics.length) + 1;
var timeoutHandle = 0;

showImg(imgIndex);

function nextImg() {
  clearTimeout(timeoutHandle);
  imgIndex++;
  showImg();
}

function prevImg() {
  clearTimeout(timeoutHandle);
  imgIndex--;
  showImg();
}

function showImg() {
  if (imgIndex>pics.length) {
    imgIndex = 1
  } else if (imgIndex<1) {
    imgIndex = pics.length
  }
  var i;
  for (i = 1; i <= pics.length; i++) {
    if (i==imgIndex) {
      pics[i-1].style.display = "block";
    } else {
      pics[i-1].style.display = "none";
    }
  }
  timeoutHandle = setTimeout(nextImg, 10000);
}
