import React, { Component } from 'react';
import ReactDOM from 'react-dom';
import {Route, IndexRoute, Router, browserHistory, Redirect} from 'react-router';
import Homepage from './Homepage';
import Comp from './Comp';
import Layout from './Layout';

export default class extends Component {
  constructor() {
    super();
  }

  render() {
    return <Router history={browserHistory}>
      <Route path='/' component={Layout}>
        <IndexRoute component={Homepage} />
        <Route path='/component' component={Comp} />
      </Route>
    </Router>
  }
}
