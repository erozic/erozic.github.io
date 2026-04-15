function getTimeRemaining(endtime) {
  var t = Date.parse(endtime) - Date.parse(new Date());
  var seconds = Math.floor(t/1000) % 60;
  var minutes = Math.floor(t/(60*1000)) % 60;
  var hours = Math.floor(t/(60*60*1000)) % 24;
  var days = Math.floor(t/(24*60*60*1000));
  return {
    'total': t,
    'days': days,
    'hours': hours,
    'minutes': minutes,
    'seconds': seconds
  };
}

function initializeCountdown(endtime) {
  var clock = document.getElementById('countdownClock');
  var daysSpan = clock.querySelector('.days');
  var hoursSpan = clock.querySelector('.hours');
  var minutesSpan = clock.querySelector('.minutes');
  var secondsSpan = clock.querySelector('.seconds');

  function updateClock() {
    var remainingTime = getTimeRemaining(endtime);

    daysSpan.innerHTML = remainingTime.days;
    hoursSpan.innerHTML = ('0' + remainingTime.hours).slice(-2);
    minutesSpan.innerHTML = ('0' + remainingTime.minutes).slice(-2);
    secondsSpan.innerHTML = ('0' + remainingTime.seconds).slice(-2);

    if (remainingTime.total <= 0) {
      clearInterval(timeinterval);
    }
  }

  updateClock();
  var timeinterval = setInterval(updateClock, 1000);
}

initializeCountdown(new Date("2026-07-18T11:00:00Z")); // this is UTC, it's -2h from Croatia time in the summer
