pipeline{
    agent any
    stages{
        stage('System Config'){
            steps{
                sh 'make --version'
                sh 'arm-none-eabi-gcc --version'
                sh 'arm-none-eabi-ld --version'
                echo 'Configure Toolchain..'
            }
        }
        stage('Unit Testing'){
            steps{
                //sh 'make'
                echo 'GoogleTest running..'
            }
        }
        stage('Build'){
            steps{
                sh 'make'
                echo 'Building..'
            }
        }
        stage('Integration Tests'){
            steps{
                //sh 'python --version'
                echo 'Pytest running..'
            }
        }
    }
}