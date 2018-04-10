angular.module('MorseTelegraphApp')
.config(['$routeProvider', function($routeProvider) {
    $routeProvider
    .when("/", {
        templateUrl : "templates/login.html",
        controller : 'loginCtrl'
    })
    .when("/login", {
        templateUrl : "templates/login.html",
        controller : 'loginCtrl'
    })
    .when("/messager", {
        templateUrl : "templates/messager.html",
        controller : 'messagerCtrl'
    })
    .otherwise("/");
}]);
