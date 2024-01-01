function getTime() {
    var date = new Date();
    var year = date.getFullYear(); //获取年份
    var month = date.getMonth() + 1; //获取月份
    var day = date.getDate(); //获取日期
    var hour = date.getHours(); //获取小时
    hour = hour < 10 ? '0' + hour : hour;
    var minute = date.getMinutes(); // 获取分
    minute = minute < 10 ? '0' + minute : minute;
    var seconds = date.getSeconds(); //获取秒
    seconds = seconds < 10 ? '0' + seconds : seconds;
    return year + '.' + month + '.' + day + '&nbsp;' + hour + ':' + minute + ':' + seconds;
}
setInterval(function() {document.querySelector('.GetTime').innerHTML = getTime();}, 1)

function getTimeR() {
    var date = new Date();
    var month = date.getMonth() + 1; //获取月份
    var day = date.getDate(); //获取日期
    var hour = date.getHours(); //获取小时
    var minute = date.getMinutes(); // 获取分
    var second = date.getSeconds(); //获取秒
    if (month == 2)
        day = day + 31;
    var finalday = 41;
    day = finalday - 1 - day;
    if (day < 0)
        return "<span style = 'font-weight: bolder;'>新年快乐！</span>";
    hour = 23 - hour;
    minute = 59 - minute;
    second = 60 - second;
    if (second == 60) {
        second = 0;
        minute = minute + 1;
    }
    if (minute == 60) {
        minute = 0;
        hour = hour + 1;
    }
    if (hour == 24) {
        hour = 0;
        day = day + 1;
    }
    hour = hour < 10 ? '0' + hour : hour;
    minute = minute < 10 ? '0' + minute : minute;
    second = second < 10 ? '0' + second : second;
    return day + "<span style = 'font-size: 0.3em;'>天</span>" + hour + ':' + minute + ':' + second;
}
setInterval(function() {document.querySelector('.GetTimeR').innerHTML = getTimeR();}, 1)
