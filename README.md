<!-- Improved compatibility of back to top link: See: https://github.com/othneildrew/Best-README-Template/pull/73 -->
<a name="readme-top"></a>
<!--
*** Thanks for checking out the Best-README-Template. If you have a suggestion
*** that would make this better, please fork the repo and create a pull request
*** or simply open an issue with the tag "enhancement".
*** Don't forget to give the project a star!
*** Thanks again! Now go create something AMAZING! :D
-->



<!-- PROJECT SHIELDS -->
<!--
*** I'm using markdown "reference style" links for readability.
*** Reference links are enclosed in brackets [ ] instead of parentheses ( ).
*** See the bottom of this document for the declaration of the reference variables
*** for contributors-url, forks-url, etc. This is an optional, concise syntax you may use.
*** https://www.markdownguide.org/basic-syntax/#reference-style-links
-->
[![Contributors][contributors-shield]][contributors-url]
[![Forks][forks-shield]][forks-url]
[![Stargazers][stars-shield]][stars-url]
[![MIT License][license-shield]][license-url]



<!-- PROJECT LOGO -->

<h3 align="center">Maveric</h3>

  <p align="center">
    This project aim to create a open source, accessible, and easy to setup and modify drone.
    <br />
    <br />
    <a href="https://github.com/morelli03/Maveric">View Demo</a>
    ·
    <a href="https://github.com/morelli03/Maveric/issues">Report Bug</a>
    ·
    <a href="https://github.com/morelli03/Maveric/issues">Request Feature</a>
  </p>
</div>



<!-- ABOUT THE PROJECT -->
## About The Project

![Product Name Screen Shot][product-screenshot]

Maveric is a drone, entirely 3D printed (here is the [model]), and it is controlled with arduino. You can modify
the code or the model to make it suitable to your needs.

The drone is divided in 6 different part, that you can print separately, and then assemble together.



<!-- GETTING STARTED -->
## Features

- **Stable flight**: The drone is able to maintain its position stable using a flight control system based on the measurement of acceleration and angular velocity.
- **Obstacle avoidance**: The drone is able to avoid obstacles in the front and under him, using a series of integrated laser sensors. (Up to 3 meters of range)
- **Automatic landing**: The drone is able to perform an automatic landing by detecting the ground using a distance sensor and gradually decreasing the altitude until it touches down safely.

### Sperimental features

- **Return to home**: The drone is able to return to its starting point by using the GPS coordinates stored at takeoff and flying back to that location.
- **Automatic flight mode**: The drone can be programmed to perform automatic flights following a predetermined path using an integrated GPS.

## Coding

To upload the program to the Arduino board that will be used as a controller, follow these steps:

1. Connect the Arduino board to your computer using a USB cable.

2. Open the Arduino IDE.

3. Select the correct port for your Arduino board from the "Tools" menu.

4. Open the program you want to upload to the Arduino board by going to "File" > "Open" in the Arduino IDE and selecting the file.

5. Click the "Upload" button in the Arduino IDE to upload the program to the Arduino board.

6. Wait for the program to finish uploading. Once it is finished, the program will start running on the Arduino board.

To upload the program to the main Arduino board , just change connection, and repeat the steps above.


## Assembly

To assemble the drone, you will need six parts: the four arms that will hold the motors and propellers, the main structure or body of the drone where the Arduino and ESCs will be placed and all the connections will be made, and the cover that will be screwed on top of the central body using screws that pass through both the central body and the arms to secure them (download 3D [models]).

To begin, place the Arduino and all the necessary connections on the main structure of the drone. There should be connections from the Arduino to the ESCs, from the batteries to a voltage sensor that will go to the Arduino, from the batteries to the ESCs, and from the ESCs to the motors passing under the arms.

Next you will need to insert the battery into the designated slot under the main structure of the drone. Make sure the battery is securely fastened and once the battery is in place, you will need to connect the cables to the ESCs in the main structure.

Next, attach the four arms to the main structure, making sure they are evenly spaced and securely fastened. Then, attach the motors and propellers to the arms.

Finally, place the cover on top of the central body and secure it with the screws, making sure it is properly aligned with the arms and the main structure. Once all the parts are in place and the connections are secure, your 3D printed drone should be ready for takeoff!

<!-- CONTRIBUTING -->
## Contributing

Contributions are what make the open source community such an amazing place to learn, inspire, and create. Any contributions you make are **greatly appreciated**.

If you have a suggestion that would make this better, please fork the repo and create a pull request. You can also simply open an issue with the tag "enhancement".
Don't forget to give the project a star! Thanks again!

<!-- LICENSE -->
## License

Distributed under the GPL-3.O License. See the [license] for more information.

<p align="right">(<a href="#readme-top">back to top</a>)</p>



<!-- MARKDOWN LINKS & IMAGES -->
<!-- https://www.markdownguide.org/basic-syntax/#reference-style-links -->
[license]: https://github.com/morelli03/Maveric/blob/master/LICENSE
[model]: https://github.com/morelli03/Maveric/blob/main/model/drone.obj
[models]: https://github.com/morelli03/Maveric/tree/main/model/parts
[contributors-shield]: https://img.shields.io/github/contributors/morelli03/Maveric.svg?style=for-the-badge
[contributors-url]: https://github.com/morelli03/Maveric/graphs/contributors
[forks-shield]: https://img.shields.io/github/forks/morelli03/Maveric.svg?style=for-the-badge
[forks-url]: https://github.com/morelli03/Maveric/network/members
[stars-shield]: https://img.shields.io/github/stars/morelli03/Maveric.svg?style=for-the-badge
[stars-url]: https://github.com/morelli03/Maveric/stargazers
[issues-shield]: https://img.shields.io/github/issues/github_username/repo_name.svg?style=for-the-badge
[issues-url]: https://github.com/github_username/repo_name/issues
[license-shield]: https://img.shields.io/github/license/morelli03/Maveric.svg?style=for-the-badge
[license-url]: https://github.com/morelli03/Maveric/blob/master/LICENSE
[linkedin-shield]: https://img.shields.io/badge/-LinkedIn-black.svg?style=for-the-badge&logo=linkedin&colorB=555
[linkedin-url]: https://linkedin.com/in/linkedin_username
[product-screenshot]: images/splashscreen.png
[Next.js]: https://img.shields.io/badge/next.js-000000?style=for-the-badge&logo=nextdotjs&logoColor=white
[Next-url]: https://nextjs.org/
[React.js]: https://img.shields.io/badge/React-20232A?style=for-the-badge&logo=react&logoColor=61DAFB
[React-url]: https://reactjs.org/
[Vue.js]: https://img.shields.io/badge/Vue.js-35495E?style=for-the-badge&logo=vuedotjs&logoColor=4FC08D
[Vue-url]: https://vuejs.org/
[Angular.io]: https://img.shields.io/badge/Angular-DD0031?style=for-the-badge&logo=angular&logoColor=white
[Angular-url]: https://angular.io/
[Svelte.dev]: https://img.shields.io/badge/Svelte-4A4A55?style=for-the-badge&logo=svelte&logoColor=FF3E00
[Svelte-url]: https://svelte.dev/
[Laravel.com]: https://img.shields.io/badge/Laravel-FF2D20?style=for-the-badge&logo=laravel&logoColor=white
[Laravel-url]: https://laravel.com
[Bootstrap.com]: https://img.shields.io/badge/Bootstrap-563D7C?style=for-the-badge&logo=bootstrap&logoColor=white
[Bootstrap-url]: https://getbootstrap.com
[JQuery.com]: https://img.shields.io/badge/jQuery-0769AD?style=for-the-badge&logo=jquery&logoColor=white
[JQuery-url]: https://jquery.com 
