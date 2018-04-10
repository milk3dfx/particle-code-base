angular.module('MorseTelegraphApp')
.controller('loginCtrl', ['$scope', 'ParticleSDK', '$window',  function($scope, $Particle, $window) {
	console.log($window.innerHeight);
	console.log('loginCtrl');
	console.log($Particle);
	$scope.userName = 'milk3dfx@gmail.com';
	$scope.error_description = '';

	
	$scope.LogIn = function(){
		$Particle.Login(
			$scope.userName,
			$scope.userPassword,
			function (response) {
				localStorage.auth = JSON.stringify(response.data)
				$window.location.href = '#/messager';
			}, 
			function (response) {
				console.log (response.data.error_description);
				console.log ('errorCallback');
				$scope.error_description = response.data.error_description;
			});
		$scope.userPassword = '';
	}
	
}]);
