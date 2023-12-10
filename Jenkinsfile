pipeline{
    agent any
    stages{
        stage('System Config'){
            steps{
                sh 'make --version'
                sh 'wget "https://developer.arm.com/-/media/Files/downloads/gnu-rm/10.3-2021.10/gcc-arm-none-eabi-10.3-2021.10-x86_64-linux.tar.bz2"'
                sh 'sudo apt-get install bzip2'
                sh 'tar -xvf gcc-arm-none-eabi-10.3-2021.10-x86_64-linux.tar.bz2'
                sh 'rm gcc-arm-none-eabi-10.3-2021.10-x86_64-linux.tar.bz2'
                sh 'export PATH="./gcc-arm-none-eabi-10.3-2021.10/bin:$PATH"'
                sh 'arm-none-eabi-gcc --version'
            }
        }
        stage('Build'){
            steps{
                sh 'make'
            }
        }
        stage('Integration Tests'){
            steps{
                sh 'python --version'
            }
        }
    }
}