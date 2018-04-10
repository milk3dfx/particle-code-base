angular.module('MorseTelegraphApp')
.service('ParticleSDK',['$http', function($http) {
    this.cloudUrl = 'https://api.particle.io'

    this.Login = function(userName, password, successCallback, errorCallback){
        var data = {
            grant_type: 'password',
            username: userName,
            password: password
        };
        password = "";
        var config = {
            headers: {
                'Content-Type': 'application/x-www-form-urlencoded',
                'Authorization': 'Basic ' + btoa('particle:particle')
                },
            transformRequest: function(obj) {
                var str = [];
                for(var p in obj){
                    str.push(encodeURIComponent(p) + "=" + encodeURIComponent(obj[p]));
                    }
                return str.join("&");
            }
        };
    
    $http.post(this.cloudUrl + '/oauth/token', data, config)
    .then(successCallback, errorCallback);
  }

  this.SendEvent = function(name, data, accessToken, successCallback, errorCallback){
    var data = {
	    'data': data,
		'ttl': '60',
		'name': name
    };

    var config = {
	    headers: {'Content-Type': 'application/json'},
		params: {'access_token': accessToken}
	};

    $http.post(this.cloudUrl + '/v1/devices/events', data, config)
    .then(successCallback, errorCallback);
  }
}]);
