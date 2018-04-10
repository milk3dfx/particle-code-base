angular.module('MorseTelegraphApp')
.controller('messagerCtrl', ['$scope', 'ParticleSDK', '$window',  function($scope, $Particle, $window) {
	console.log('messagerCtrl');
	var auth = JSON.parse(localStorage.auth);
	if (!auth){
		$window.location.href = '#/login';
	}
	
	$scope.messageText = 'I love You';

	$scope.SendMessage = function(){
		$Particle.SendEvent('message', $scope.messageText, auth.access_token,
			function (response) {
				console.log ('Done.');
			}, 
			function (response) {
				console.log (response.data.error_description);
			});
	}
	
	$scope.LogOut = function(){
		console.log("Logout");
		$window.location.href = '#/login';
		localStorage.auth = null;
	}
	
}]);
