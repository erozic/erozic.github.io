var imgIndex = 1;
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
	var pics = document.getElementsByClassName("welcome_pic");
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