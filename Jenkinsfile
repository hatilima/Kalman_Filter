pipeline{
    agent any
    stages{
        stage('System Config'){
            steps{
                sh 'make --version'
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